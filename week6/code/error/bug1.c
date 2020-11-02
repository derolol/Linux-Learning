#include "../ch6.h"

int *p, x;
int main() {
	int *q;
	p = &x;
	*p = 1;
	q = (int *)malloc(sizeof(int));
	*q = 2;
	printf("*p = %d, *q = %d\n", *p, *q);
	
	return 0;
}
