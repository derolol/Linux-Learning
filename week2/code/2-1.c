#include "ch2.h"
int main() {
	int ret;
	ret = write(1, "Hello Wrold!\n", 13);
	exit(0);
}
