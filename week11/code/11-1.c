#include "ch11.h"

int main()
{
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		perror("fork pid error!\n");
		exit(-1);
	}
	else if (pid == 0)
	{
		printf("child : pid = %d, ppid = %d\n", getpid(), getppid());
		exit(88);
	}
	else
	{
		int s, r;
		r = wait(&s);
		printf("parent : exit code %d\n", WEXITSTATUS(s));
		return 0;
	}
}
