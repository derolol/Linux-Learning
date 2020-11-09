#include "./ch8.h"

int i = 1;

void stack() {
	int a, b;
	printf("count: %d, a: %x, b: %x\n", i++, &a, &b);
	stack();
}

int main() {
	stack();
	return 0;
}
