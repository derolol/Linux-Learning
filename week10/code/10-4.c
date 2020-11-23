#include "ch10.h"

// 没有派生子进程

int main() {
	int r;
	printf("10-4: pid = %d, ppid = %d\n", getpid(), getppid());
	r = execl("./test", "./test", "hello", "world", NULL);
	if (r == -1) {
		perror("execl failed!\n");
		exit(-1);
	}
	printf("After Calling!\n");
	return 0;
}
