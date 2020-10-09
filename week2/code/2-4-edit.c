#include "ch2.h"
int main() {
	int i;
	int cnt = 0;
	while(1) {
		char name[64];
		snprintf(name, sizeof(name), "%d.txt", cnt);
		int fd = creat(name, 0644);
		close(fd);
		cnt++;
		if (cnt == 2000 && fd != -1) break;
	}
	printf("Successfully create 2000 file!\n");
	return 0;
}
