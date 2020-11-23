#include "ch10.h"

int main() {
	int r, son;
	printf("10-4: pid = %d, ppid = %d\n", getpid(), getppid());
	son = fork();
	if (son < 0)
	{
		perror("fork failed");
		exit(-1);
	}
	else if (son == 0)
	{
		r = execl("./test", "./test", "hello", "world", NULL);
		if (r == -1) {
			perror("execl failed!\n");
			exit(-1);
		}
		exit(0);
	}
	else {
		wait(NULL);
		printf("After Calling!\n");
	}
	return 0;
}
