#include "ch3.h"

/*
 * 产生指定文件描述符的备份
 * 新旧指针指向的是统一内存地址的系统文件表项
 */

int main() {
	int d1, d2;
	char buf[5];

	memset(buf, 0, 5);
	d1 = open("file.hole", O_RDONLY);
	d2 = dup(d1);
	printf("d1 = %d, d2 = %d\n", d1, d2);
	lseek(d1, 5, SEEK_SET);
	read(d2, buf, 4);

	printf("buf: %s\n", buf);

	return 0;
}
