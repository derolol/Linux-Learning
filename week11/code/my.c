#include "my.h"

// 1. process tree and wait relation
// 2. father build file write
// 3. generate

char* getCurrentTime()
{
	char * tbuf;
	tbuf = malloc(sizeof(char) * 100);
	memset(tbuf, 0, 100);
	struct timeval tv;
	struct tm *t;

	gettimeofday(&tv, NULL);
	t = localtime(&tv.tv_sec);
	
	sprintf(tbuf, "%d-%d-%d %d:%d:%d.%ld", 1900+t->tm_year, 1+t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, tv.tv_usec);
	return tbuf;
}

void printInfo(char* object)
{
	printf("%s : pid = %d ppid = %d exit time = %s\n", object, getpid(), getppid() ,getCurrentTime());
}

void writeInfo(FILE *fp, char* object)
{
	fprintf(fp, "%s : pid = %d exit time = %s\n", object, getpid(), getCurrentTime());
}
