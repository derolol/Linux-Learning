#include "./ch8.h"

int main() {
	int i, max = 1024*1024;
	char *space;
	for (i = 0; i < max; i++) {
		space = (char *)malloc(sizeof(char) * i * max);
		if (!space) {
			printf("Current space: %dMB\n", i);
			break;
		}
		printf("Current space: %dMB, space: %x\n", i, space);
	}
	return 0;
}
