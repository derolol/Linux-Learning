#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>
#include <setjmp.h>
#include <wait.h>
#include <errno.h>

void err_exit(char* s);

char* getCurrentTime();
void printInfo(char* object);
void writeInfo(FILE *fp, char *object);
