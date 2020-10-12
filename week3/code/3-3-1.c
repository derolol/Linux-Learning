#include "ch2.h"

int main() {
	int ret;
	char buffer[200];
	FILE *fp;
	
	memset(buffer, 0, sizeof(buffer));

	if ((fp = fopen("./test2.txt", "w")) != NULL) {
		printf("file fp = %d\n", fp->_fileno);

		fgets(buffer, sizeof(buffer), stdin);
		buffer[strlen(buffer)-1] = '\0';
		printf("The content of your input is: %s.\n", buffer);
		
		ret = fwrite(buffer, 1, strlen(buffer), fp);
		printf("Successfully write %d items.\n", ret);
		
		fclose(fp);
	}
	else {
		perror("Open Failed!\n");
	}

	return 0;
}

