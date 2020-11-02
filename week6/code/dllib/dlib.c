#include "../ch6.h"

void dynamic_lib_call(void) {
	printf("Dynamic lib is called!\n");
}

void dsum(int max) {
	int res = (1 + max) * max / 2;
	printf("sum = %d\n", res);
}
