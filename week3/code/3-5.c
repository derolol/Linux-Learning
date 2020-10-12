#include "ch2.h"

/* 
 * 将文件描述符以读写的方式和文件流指针联系起来了
 * 通过该文件流将字符串输出到文件描述符为1的文件中
 * 即标准输出设备屏幕上
 */

int main() {
	FILE* fp;
	fp = fdopen(1, "w+");
	fprintf(fp, "test data %s\n", "hello world");
	fclose(fp);
	return 0;
}
