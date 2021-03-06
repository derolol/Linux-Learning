#include "ch11.h"

int main()
{
	pid_t pid1;
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork1 wrong!\n");
		exit(-1);
	}
	else if (pid1 == 0)
	{
		printf("child1 : pid = %d, ppid = %d\n", getpid(), getppid());
		exit(0);
	}
	else
	{
		pid_t pid2;
		pid2 = fork();
		if (pid2 < 0)
		{
			perror("fork2 wrong!\n");
			exit(-1);
		}
		else if (pid2 == 0)
		{
			printf("child2 : pid = %d, ppid = %d\n", getpid(), getppid());
			while(1);
			exit(0);
		}
		else
		{
			int s1, r1, s2, r2;
			r1 = waitpid(pid1, &s1, 0);
			r2 = waitpid(pid2, &s2, WNOHANG);
			if (WIFEXITED(s1))
			{
				printf("parent wait for child1 %d : exit code %d\n", r1, WEXITSTATUS(s1));
			}
			else
			{
				if (WIFSIGNALED(s1))
					printf("pid %d exit with signal %d\n", r1, WTERMSIG(s1));
			}
			if (WIFEXITED(s2))
			{
				printf("parent wait for child2 %d : exit code %d\n", r2, WEXITSTATUS(s2));
			}
			else
			{
				if (WIFSIGNALED(s2))
					printf("pid %d exit with signal %d\n", r2, WTERMSIG(s2));
			}
			printf("parent finished!\n");
			return 0;
		}
	}
}
