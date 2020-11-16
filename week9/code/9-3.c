#include "./ch9.h"

int g_int = 1;

int main() {
	int fd_in, fd_out;
	char buf[1024];
	pid_t pid;
	memset(buf, 0, 1024);
	fd_in = open(INFILE, O_RDONLY);
	if (fd_in < 0) {
		fprintf(stderr, "Failed to open %s, reason(%s)\n", INFILE, strerror(errno));
		return 1;
	}
	fd_out = open(OUTFILE, O_WRONLY | O_CREAT | O_TRUNC, MODE);
	pid = fork();
	if (pid < 0) {
		fprintf(stderr, "Failed to fork, reason(%s)\n", strerror(errno));
		return 1;
	}
	while (read(fd_in, buf, 2) > 0) {
		printf("%d: %s", getpid(), buf);
		sprintf(buf, "%d Hello world!\n", getpid());
		write(fd_out, buf, strlen(buf));
		sleep(1);
		memset(buf, 0, 1024);
	}
}
