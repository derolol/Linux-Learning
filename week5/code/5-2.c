#include "ch5.h"

int main() {
	int fd;
	FILE* fp;
	char* s = "Hello World!\n";

	if ((fd = open("./test1.txt", O_CREAT|O_WRONLY, 0644)) == -1) {
		err_exit("Error to create file");
	}
	if ((fp = fopen("./test2.txt", "w+")) == NULL) {
		err_exit("Error to create file");
	}

	sleep(15);
	write(fd, s, strlen(s));
	fwrite(s, sizeof(char), strlen(s), fp);

	printf("After write\n");
	sleep(15);

	close(fd);
	return 0;
}
