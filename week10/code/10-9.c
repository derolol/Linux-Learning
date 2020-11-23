#include "ch10.h"

void pr_exit(int status, pid_t pid)
{
	int sig;
	if (WIFEXITED(status))
		printf("process %d normal termination, exit status = %d\n", pid, WEXITSTATUS(status));
	else if (WIFSIGNALED(status)) {
		sig = WTERMSIG(status);
		printf("process %d abnormal termination, signal number = %d%s:\n", pid, sig,
#ifdef WCOREDUMP
				WCOREDUMP(status) ? "(core file generated)" : "");		
#else
		"");
#endif
		psignal(sig, "");
	}
	else if (WIFSTOPPED (status)) {
		sig = WSTOPSIG(status);
		printf("proces %d stopped, signal number = %d: ", pid, sig);
		psignal(sig, "");
	}
}

int zero = 0;

int main(void) {
	pid_t pid;
	int status;
	if ((pid = fork()) == 0)
		exit(0);
	if ((pid = fork()) == 0)
		abort();
	if ((pid = fork()) == 0) {
		status /= zero;
		exit(0);
	}
	while ((pid = wait(&status)) >= 0)
		pr_exit(status, pid);
	perror("wait over");
	exit(EXIT_SUCCESS);
}
