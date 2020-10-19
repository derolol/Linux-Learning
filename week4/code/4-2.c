#include "ch3.h"

/*
 * 移动文件指针写文件，产生文件空洞
 */

char buf1[] = "abcdefghij";
char buf2[] = "0123456789";

int main() {
	int fd;
	if ((fd = open("file.hole", O_WRONLY | O_CREAT, 0644)) < 0)
		err_exit("Create error!");
	if (write(fd, buf1, 10) != 10)
		err_exit("Write error!");
	if (lseek(fd, 40, SEEK_SET) == -1)
		err_exit("Lseek error!");
	if (write(fd, buf2, 10) != 10)
		err_exit("Write error!");
	return 0;
}
