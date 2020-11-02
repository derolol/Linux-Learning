#include "ch6.h"

// c语言的构造函数
static void __attribute__ ((constructor)) before_main() {
	printf("---------------Before Main-----------------\n");
}

// c语言的
static void __attribute__ ((destructor)) after_main() {
	printf("---------------After Main------------------\n");
}

int main() {
	printf("--------------Main Function----------------\n");
	return 0;
}
