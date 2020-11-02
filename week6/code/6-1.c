#include "ch6.h"
static void __attribute__ ((constructor)) before_main() {
	printf("---------------Before Main-----------------\n");
}

static void __attribute__ ((destructor)) after_main() {
	printf("---------------After Main------------------\n");
}

int main() {
	printf("--------------Main Function----------------\n");
	return 0;
}
