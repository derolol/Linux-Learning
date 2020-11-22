#include "./ch9.h"
char *env_init[] = {"USER=stu", "PATH=/tmp", NULL};
int main() {
	if (execle("./test", "./test", "hello", "world\n", NULL, env_init) == -1) {
		perror("execve!\n");
		exit(EXIT_FAILURE);
	}
	puts("Never get here!\n");
	exit(EXIT_SUCCESS);
}
