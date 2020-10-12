#include "ch2.h"

/*
 * 通过获取命令行参数实现将参数内容写入文件中
 * 存在问题 -> buffer的使用冗余
 */

int main(int argc, char* argv[]) {
	FILE* fp;
	char buffer[200];

	memset(buffer, 0, sizeof(buffer));
	
	printf("Out file: %s\n", argv[1]);
	
	if ((fp = fopen(argv[1], "w")) != NULL) {
		for (int i = 2; i < argc; i++) {
			strcat(buffer, argv[i]);
			strcat(buffer, " ");
		}
		printf("Output content: %s\n", buffer);
		
		fwrite(buffer, 1, strlen(buffer), fp);
		fclose(fp);
	}

	else perror("Create File Failed.\n");
	
	return 0;
}
