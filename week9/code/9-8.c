#include "./ch9.h"

int g = 0;
pid_t pid[2];

int main() {
	int i, j;

	FILE *fp;
	fp = fopen("./test.txt", "w+");

	for (i = 0; i < 2; i++) {
		pid[i] = fork();

		if (pid[i] == 0) {
			g++;

			printf("I am %d, my parent is %d\n", getpid(), getppid());
			
			if (i == 0) {
				for (j = 0; j < 2; j ++) {
					pid[j] = fork();
					
					if (pid[j] == 0) {
						g++;
						fprintf(fp, "%d: g = %d\n", getpid(), g*2+j);
						printf("I am %d, my parent is %d\n", getpid(), getppid());
						
						exit(0);
					}

				}

				for(j = 0; j < 2; j ++) {
             		   		waitpid(pid[j], NULL, 0);
            			}
				
			}

			fprintf(fp, "%d: g = %d\n", getpid(), g*2 + i);

			exit(0);
		}
	}

	for (i = 0; i < 2; i++) {
		waitpid(pid[i], NULL, 0);
	}

	printf("I am parent %d\n", getpid());
	g++;
	fprintf(fp, "%d: g = %d", getpid(), g);
	
	return 0;
}
