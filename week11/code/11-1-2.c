#include "ch11.h"

char* translateSignal(int signal)
{
	switch(signal)
	{
		case SIGKILL:
			return "process is killed by command 'kill -9'";
		case SIGTERM:
			return "process is killed by command 'kill'";
		case SIGFPE:
			return "process has wrong caculation";
	}
}

void handleSignal(int status, pid_t pid)
{
	int sig;
	if (WIFEXITED(status))
	{
		printf("[receive signal] process %d exit status: %d\n", pid, WEXITSTATUS(status));
	}
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		printf("[receive signal] process %d abnormal termination (%d - %s)\n", pid, sig, translateSignal(sig));
	}
	if (WIFSTOPPED(status))
	{
		sig = WSTOPSIG(status);
		printf("[receive signal] process %d stopped (%d - %s)\n", pid, sig, translateSignal(sig));
	}
}

int main()
{
	pid_t pid1, pid2, pid3;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork1 wrong!\n");
		exit(-1);
	}
	else if (pid1 == 0)
	{
		printf("[child %d] exit code = 99\n", getpid());
		exit(99);
	}
	else
	{

		pid2 = fork();
		if (pid2 < 0)
		{
			perror("fork2 wrong!\n");
			exit(-1);
		}
		else if (pid2 == 0)
		{
			printf("[child %d] exit code = 28\n", getpid());
			exit(28);
		}
		else
		{
			
			pid3 = fork();
			if (pid3 < 0)
			{
				perror("fork3 wrong!\n");
			}
			else if (pid3 == 0)
			{
				int a = 0, b = 5;
				printf("[child %d]\n", getpid());
				// abort();
				// a = b/a;
				while(1) ;
				exit(13);
			}
			else
			{
				int s1, r1, s2, r2, s3, r3;
				r1 = wait(&s1);
				r2 = wait(&s2);
				r3 = wait(&s3);
				handleSignal(s1, r1);
				handleSignal(s2, r2);
				handleSignal(s3, r3);
				return 0;
			}	
	}
	}
	return 0;
}
