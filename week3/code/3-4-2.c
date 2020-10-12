#include "ch2.h"

/* fwrite每次写多字节所耗费的时间 */

int main() {
	FILE* fin,* fout;
	char buffer[5000];

	if ((fin = fopen("./test1.txt", "r")) != NULL) {
		if ((fout = fopen("./test4.txt", "w")) != NULL) {
			fgets(buffer, sizeof(buffer), fin);
			fwrite(buffer, sizeof(buffer), 1, fout);
			fclose(fout);
		}
		fclose(fin);
	}
	return 0;
}
