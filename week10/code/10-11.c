#include "ch10.h"

// system(const char *)

// sprintf() cat string
// main() recive argument
// ./test2 ps -ef 

int main(int argc, char **argv) {
	int cur = 0;
	char buffer[200];
	memset(buffer, 0, 200);
	cur += sprintf(buffer, "%s", argv[1]);
	for (int i = 2; i < argc; i++) {
		cur += sprintf(buffer+cur, " %s", argv[i]);
	}
	system((const char *) buffer);
	return 0;
}
