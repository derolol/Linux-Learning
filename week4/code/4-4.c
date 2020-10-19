#include "ch3.h"

/*
 * 一个进程用同一个方式打开同一个文件
 * 两个文件描述符指向的是不同的系统文件表项
 * 指针的移动是对内存中的文件指针进行移动
 * 两个文件描述符移动指针的操作互不影响
 */

int main() {
	int d1, d2;
	char buf[5];

	memset(buf, 0, 5);
	d1 = open("file.hole", O_RDONLY);
	d2 = open("file.hole", O_RDONLY);
	printf("d1 = %d, d2 = %d\n", d1, d2);
	lseek(d1, 5, SEEK_SET);
	read(d2, buf, 4);

	printf("buf: %s\n", buf);

	return 0;
}
