#include "ch3.h"

/*
 * 将程序4-2的打开文件方式转换为增加
 * 每次往文件写入的时候都从文件尾开始写
 */

char buf1[] = "abcdefghij";
char buf2[] = "0123456789";

int main() {
	int fd;
	if ((fd = open("file.hole", O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
		err_exit("Create error!");
	if (write(fd, buf1, 10) != 10)
		err_exit("Write error!");
	if (lseek(fd, 40, SEEK_SET) == -1)
		err_exit("Lseek error!");
	if (write(fd, buf2, 10) != 10)
		err_exit("Write error!");
	return 0;
}
