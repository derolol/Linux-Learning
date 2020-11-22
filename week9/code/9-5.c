#include "./ch9.h"

int main() {
	pid_t i;
	i = vfork();
	if (i < 0) {
		perror("Vfork failed!\n");
		exit(-1);
	}
	else if (i == 0) {
		printf("child: pid = %d, ppid = %d, i = %d\n", getpid(), getppid(), i);
		_exit(0); // 不能用 return 会导致资源被释放
	}
	else {
		wait(NULL);
		printf("parent: pid = %d, ppid = %d, i = %d\n", getpid(), getppid(), i);
		return 0;
	}
}
