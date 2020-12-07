#include "ch11.h"

int main()
{
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		perror("fork wrong!\n");
		exit(-1);
	}
	else if (pid == 0)
	{
		printf("pid = %d, ppid = %d\n", getpid(), getppid());
		exit(0);
	}
	else {
		int r;
		r = waitpid(pid, 0, WNOHANG);
		printf("wait process %d\n", r);
		return 0;
	}
	return 0;
}
