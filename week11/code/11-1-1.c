#include "ch11.h"

int main()
{
	pid_t pid1, pid2;
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork pid error!\n");
		exit(-1);
	}
	else if (pid1 == 0)
	{
		printf("child1 : pid = %d, ppid = %d\n", getpid(), getppid());
		exit(0);
	}
	else
	{
		pid2 = fork();
		if (pid2 < 0)
		{
			perror("fork pid error!\n");
		}
		else if (pid2 == 0)
		{
			printf("child2 : pid = %d, ppid = %d\n", getpid(), getppid());
			exit(0);
		}
		else
		{
			int s, r1, r2;
			r1 = wait(&s);
			if (r1 == pid1)
				printf("Hello child1[%d]!\n", r1);
			if (r1 == pid2)
				printf("Hello child2[%d]!\n", r1);
			r2 = wait(&s);
			if (r2 == pid1)
				printf("Hello child1[%d]!\n", r2);
			if (r2 == pid2)
				printf("Hello child2[%d]!\n", r2);
			printf("parent : exit code %d\n", WEXITSTATUS(s));
			return 0;
		}
	}
}
