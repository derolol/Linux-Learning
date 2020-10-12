#include "ch2.h"

/*
 * 将打开的文件以另一种模式重新打开一次
 */

int main() {
	FILE* fp;
	char buffer[80];

	memset(buffer, 0, sizeof(buffer));
	
	fp = fopen("./test5.txt", "a+");
	fputs("\tappend new infomation!", fp);

	fp = freopen("./test5.txt", "r", fp);
	fgets(buffer, sizeof(buffer), fp);
	printf("Content of file: %s\n", buffer);

	fclose(fp);
	return 0;
}
