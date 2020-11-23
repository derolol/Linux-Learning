#include "ch10.h"

// 108 99
// waitpid
// print status

int main() {
	int status;
	int pid1, pid2;
	
	pid1 = fork();

	if (pid1 < 0) {
		perror("fork1 failed");
		exit(-1);
	}
	else if (pid1 == 0) {
		printf("[child1] pid = %d, ppid = %d\n", getpid(), getppid());
		exit(108);
	}
	else {
		int ret1, ret2;

		pid2 = fork();

		if (pid2 < 0) {
			perror("fork2 failed");
			exit(-1);
		}
		else if(pid2 == 0) {
			printf("[child2] pid = %d, ppid = %d\n", getpid(), getppid());
			exit(99);
		}
		else {
			ret1 = waitpid(pid1, &status, 0);
			// ret1 = while(!waitpid(pid1, &status, WNOHANG)) ;
			printf("pid = %d, status = %d\n", ret1, WEXITSTATUS(status));
			ret2 = waitpid(pid2, &status, 0);
			// ret2= while(!waitpid(pid2, &status, WNOHANG)) ;
			printf("pid = %d, status = %d\n", ret2, WEXITSTATUS(status));
			return 0;
		}
	}
}
