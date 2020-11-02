#include "ch6.h"

int main(int argc, char *argv[], char *env[]) {
	extern char** environ;
	int i;
	// 引用外部符号environ（环境指针->找到环境表）
	for (i = 0; environ[i]; i++) {
		printf("emviron[%d] = %s\n", i, environ[i]);
	}
	// mian函数的环境变量
	for (i = 0; env[i]; i++) {
		printf("env[%d] = %s\n", i, env[i]);
	}
	// 通过函数调用获取单个环境变量值
	printf("PATH = %s\n", getenv("PATH"));
	return 0;
}
