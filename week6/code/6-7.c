#include "ch6.h"

// [PROBLEM] How to let the program print 'test' when second search
// setenv(name, value, rewrite)
// putenv Linux下putenv只对当前函数有效
// setenv setenv函数设置的环境变量只在本进程，而且是本次执行中有效
// unsetenv

int i = 1;

// 通过setenv对本次进程的环境变量进行设置
static void set_env_string_edit(void) {
	char name[] = "test_env";
	char value[] = "test";
	if (setenv(name, value, 1) != 0) {
		printf("Setenv is failed!\n");
	}
	printf("%d.[setenv]The test_env = %s\n", i++, getenv("test_env"));
}

// 通过putenv对本函数执行时的环境变量进行设置
static void set_env_string(void) {
	char test_env[] = "test_env=test";
	if (putenv(test_env)!=0) {
		printf("Putenv is failed!\n");
	}
	printf("%d.[putenv]The test_env = %s\n", i++, getenv("test_env"));
}

static void show_env_string() {
	printf("%d.The test_env = %s\n", i++, getenv("test_env"));
}

int main() {
	set_env_string();
	show_env_string();
	set_env_string_edit();
	show_env_string();
	return 0;
}
