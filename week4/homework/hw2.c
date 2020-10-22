/*
 * 2.10-7
 * 为什么说gets()是危险的函数？
 * 【答】因为它没有为字符串s的溢出提供保护。当要读入的行长度超过字符串s所能容纳的大小时，超出的部分将越过s提供的空间而覆盖其他的数据或程序。
 */

#include "ch3.h"
#define BUF_SIZE 8

int main() {
	FILE* fp;
	int fgets_yes;
	struct iobuf {
		char buf[BUF_SIZE];
		char others[BUF_SIZE];
	} buffer;
	
	do {
		// 将缓冲区初始化
	        memset(&buffer, 0, sizeof(struct iobuf));

		// 根据用户选择使用fgets()和gets()函数读取用户输入
		fgets_yes = y_or_n_ques("Should we read by fgets()?");
		fprintf(stdout, "PLease enter a line\n");
		// 用户选择fgets()
		if (fgets_yes) {
			// 从标准输入读入最大BUF_SIZE的数据
			fgets(buffer.buf, BUF_SIZE, stdin);
			// 将读入的数据输出
			fprintf(stdout, "fgets() get string \"%s\"\n", buffer.buf);
			// 若一行数据没有读完则继续
			while(buffer.buf[strlen(buffer.buf)-1] != '\n') {
				fgets(buffer.buf, BUF_SIZE, stdin);
				fprintf(stdout, "fgets() get string \"%s\"\n", buffer.buf);
			}
		}
		// 用户选择gets()
		else {
			// 提供要存储输入的数组地址
			gets(buffer.buf);
			// 将输入的内容打印
			fprintf(stdout, "gets() get string \"%s\"\n", buffer.buf);
		}
		// 将读入的缓冲区的后一个地址位置的内容进行输出
		fprintf(stdout, "buffer.others is \"%s\"\n", buffer.others);
	} while (y_or_n_ques("Continue?")); // 询问用户是否要继续

	return 0;
}
