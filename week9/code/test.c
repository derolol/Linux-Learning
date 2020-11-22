#include "./ch9.h"
int main(int argc, char *argv[]) {
	extern char **environ;
	char **env = environ;
	int i;
	if (argc <= 1) err_exit("Param wrong!\n");
	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("Environment var:\n");
	while(*env) {
		printf("%s\n", *env);
		env++;
	}
	exit(EXIT_SUCCESS);
}
