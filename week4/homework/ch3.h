#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
void err_exit(char* s) {
	printf("USAGE : %s is failed.\n", s);
	exit(1);
}

int y_or_n_ques(char* s) {
	char ans;
	printf("%s\n", s);
	ans = getchar();
	getchar();
	if (ans == 'y' || ans == 'Y') return 1;
	return 0;
}
