#include "ch3.h"

/* 
 * 通过命令行参数指定复制的源文件以及目标文件
 * 每次写入1024字节
 */

int main (int argc, char** argv) {
	int n, from, to;
	char buf[1024];
	if (argc != 3) {
		printf("Usage : %s from-file to-file\n", argv[0]);
		exit(0);
	}
	if ((from = open(argv[1], O_RDONLY)) < 0) {
		perror(argv[1]);
		exit(1);
	}
	if ((to = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0) {
		perror(argv[2]);
		exit(1);
	}
	while ((n = read(from, buf, sizeof(buf))) > 0)
		write(to, buf, n);
	close (from);
	close (to);

	return 0;
}
