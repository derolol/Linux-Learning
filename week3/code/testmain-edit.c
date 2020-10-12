#include "ch2.h"

/*
 * 通过fprintf函数格式化输出从main函数获取的参数
 */

int main(int argc, char* argv[]) {
	FILE* fp;
	printf("Out file: %s\n", argv[1]);
	
	if ((fp = fopen(argv[1], "w")) != NULL) {
		fprintf(fp, "%s", argv[2]);
		for (int i = 3; i < argc; i++) {
			// fwrite(argv[i], 1, strlen(argv[i]), fp);
			fprintf(fp, " %s", argv[i]);
		}
		fclose(fp);
	}

	else perror("Create File Failed.\n");
	
	return 0;
}
