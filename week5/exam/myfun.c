#include "my.h"

char *title[] = {"  userid", " name", "   htel", "    tel"};

recorder* input() {
	int id;
	size_t str_size;
	size_t *size = (size_t *) malloc(sizeof(size_t));
	char **buf_ptr = (char **) malloc(sizeof(char*));
	recorder* r = (recorder*) malloc(sizeof(recorder));
	memset(r, 0, sizeof(recorder));

	fputs("Please input your id: ", stdout);
	fscanf(stdin, "%d", &(r->id));
	fgetc(stdin);
	
	*size = 0;
	*buf_ptr = NULL;
	fputs("Please input your name: ", stdout);
	getline(buf_ptr, size, stdin);
	str_size = strlen(*buf_ptr)-1 > 7 ? 7 : strlen(*buf_ptr)-1;
	strncpy(r->name, *buf_ptr, str_size);

	*size = 0;
        *buf_ptr = NULL;
	fputs("Please input your telephone number: ", stdout);
	getline(buf_ptr, size, stdin);
	str_size = strlen(*buf_ptr)-1 > 11 ? 11 : strlen(*buf_ptr)-1;
	strncpy(r->htel, *buf_ptr, str_size);

	*size = 0;
	*buf_ptr = NULL;
	fputs("Please input your phone number: ", stdout);
	getline(buf_ptr, size, stdin);
	str_size = strlen(*buf_ptr)-1 > 11 ? 11 : strlen(*buf_ptr)-1;
	strncpy(r->tel, *buf_ptr, str_size);

	return r;
}

void save(recorder* r) {
	int ret;
	FILE *fp;
	if ((fp = fopen("./user.dat", "r")) == NULL) {
		if ((fp = fopen("./user.dat", "w+")) == NULL) {
			err_exit("Create file");
		}
		if ((ret = fprintf(fp, "%-10s\t%-7s\t%-11s\t%-11s", title[0], title[1], title[2], title[3])) == 0) {
			err_exit("Add title");
		}
	}
	else {
		if ((fp = freopen("./user.dat", "a+", fp)) == NULL) {
			err_exit("Open file");
		}
	}
	if ((ret = fprintf(fp, "\n%010d\t%-7s\t%11s\t%11s", r->id, r->name, r->htel, r->tel)) == 0) {
		err_exit("Write message");
	}
}

int ascname(const void *p1, const void *p2) {
	return strcmp(* (char * const *) ((recorder *)p1)->name, * (char * const *) ((recorder *)p2)->name);
}

int descname(const void *p1, const void *p2) {
        return strcmp(* (char * const *) ((recorder *)p2)->name, * (char * const *) ((recorder *)p1)->name);
}

void mysort() {
	char ch;
	fputs("Sortint in ascending order (1) or in a descending order (0) ? ");
	ch = fgetc(stdin);
	switch(ch) {
		case '1': 
			break;
		case '0':
			break;
		default:
	}
}

