#include "test.h"

int son[2];

int main() {
	int i, state;
	
	for (i = 0; i < 2; i++) {
		son[i] = fork();

		if (son[i] < 0)
			err_exit("Fork Failed");

		if (son[i] == 0) {
			// son process
			
			printf("I am %d, my father is %d\n", getpid(), getppid());

			if (i == 0) {
				// first son
				
				for (i = 0; i < 2; i++) {
					son[i] = fork();

					if (son[i] < 0)
						err_exit("Fork Second Failed");

					if (son[i] == 0) {
						// son process
						printf("I am %d, my father is %d\n", getpid(), getppid());
						exit(0);
					}
					
					if (son[i] > 0) {
						// father process
						wait(&state);
						printf("I am %d, my son has finished his job. My father is %d.\n", getpid(), getppid());
					}
				}
			}

			exit(0);

		}

		if (son[i] > 0) {
			// father process
			wait(&state);
			printf("I am %d, my son has finished his job.\n", getpid());
		}
	}

	printf("End.\n");
}
