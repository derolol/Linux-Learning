#include "ch3.h"

/*
 * 4-7-1和4-7-2程序两个进程同时运行
 * 同时对同一文件进行写入
 * 每次写入时，将指针移动到当前位置的后10字节
 */

int main() {
	char c;
	int fd = open("out.dat", O_CREAT | O_WRONLY, 0644);

	while(1) {
		for (int i = 0; i < 26; i++) {
			c = 'A' + i;
			write(fd, &c, 1);
			printf("Writing character %c.\n", c);
			lseek(fd, 10, SEEK_CUR);
			sleep(5);
		}
	}

	close(fd);

	return 0;
}
