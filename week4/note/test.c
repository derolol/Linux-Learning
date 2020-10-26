#include <stdio.h>
#include <unistd.h>

int main() {
	char buffer[1024];
	int status = gethostname(buffer, sizeof(buffer));
	printf("status: %d, hostname: %s", status, buffer);
	return 0;
}
