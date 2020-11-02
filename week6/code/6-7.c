#include "ch6.h"

// [PROBLEM] How to let the program print 'test' when second search
// setenv(name, value, rewrite)
// putenv
// unsetenv

static void set_env_string(void) {
	char test_env[] = "test_env=test";
	if (putenv(test_env)!=0) {
		printf("Putenv is failed!\n");
	}
	printf("1. The test_env = %s\n", getenv("test_env"));
}

static void show_env_string() {
	printf("2. The test_env = %s\n", getenv("test_env"));
}

int main() {
	set_env_string();
	show_env_string();
	return 0;
}
