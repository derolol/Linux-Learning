#include "ch3.h"

int main() {
	char c;
	int fd = open("out.dat", O_CREAT | O_WRONLY, 0644);

	while(1) {
		for (int i = 0; i < 26; i++) {
			c = 'a'+i;
			write(fd, &c, 1);
			printf("Writing character %c\n", c);
			lseek(fd, 10, SEEK_CUR);
			sleep(10);
		}
	}

	close(fd);

	return 0;
}
