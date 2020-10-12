#include "ch2.h"

/*
 * 将新建的文件的文字描述符与文件流指针联系起来
 */

int main(int argc, char* argv[]) {
	int fd = open("./test4.txt", O_RDWR);
	FILE* fp = fdopen(fd, "w+");
	fwrite(argv[1], 1, strlen(argv[1]), fp);
	close(fd);
	return 0;
}
