#ifndef _MY_H
#define _MY_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define err_exit(MSG) {\
	printf("USAGE : %s is failed.\n", MSG);\
	exit(1);\
}

typedef struct user {
	int id;
	char name[8];
	char htel[12];
	char tel[12];
} recorder;

recorder* input();
void save(recorder* r);

#endif
