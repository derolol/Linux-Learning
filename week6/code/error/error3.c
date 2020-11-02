#include "../ch6.h"

int main() {
	char s[128];
	memset(s, 0, sizeof(s));
	strcpy(s, "hello world!");
	printf("s = %s\n", s);
	return 0;
}
