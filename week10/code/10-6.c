#include "ch10.h"

int main() {
	int son;
	printf("10-6: pid = %d, ppid = %d\n", getpid(), getppid());
	son = fork();
	if (son < 0)
	{
		perror("fork failed");
		exit(-1);
	}
	else if (son == 0)
	{
		int r;
		printf("10-6 child: pid = %d, ppid = %d\n", getpid(), getppid());
		execl("./test", "./test", "hello", "world", NULL);
		if (r == -1) {
			perror("execl failed!\n");
			exit(-1);
		}
		printf("10-6 child end!\n");
		exit(1);
	}
	else {
		int r, s;
		r = wait(&s);
		printf("10-6: r = %d, status = %d\n", r, WEXITSTATUS(s));
		return 0;
	}
}
