#include "my.h"

list *records = NULL;
char *title[] = {"  userid", " name", "   htel", "    tel"};

void release() {
	if (!records) {
		records = (list *) malloc(sizeof(list));
		records->r = NULL;
	}
	if (records->r) free(records->r);
	records->size = 0;
	records->r = NULL;
}

list* getRecords() {
	int end = 0, cur = 0;
	FILE *fp;

	if ((fp = fopen("./user.dat", "r+")) == NULL) {
                fputs("No information exist!\n", stdout);
                return NULL;
        }

	release();
	fseek(fp, 0, SEEK_END);
        end = ftell(fp);
        records->size = (end + 1) / 43 - 1;
        records->r = (record *) malloc(sizeof(record) * (records->size));

        fseek(fp, 43, SEEK_SET);
       	for(cur = 0; cur < records->size; cur++) {
               	fscanf(fp,
			"%u%s%s%s",
			&((records->r)[cur].id),
			(records->r)[cur].name,
			(records->r)[cur].htel,
			(records->r)[cur].tel);
       	}
	
	fclose(fp);
	return records;
}

int checkId(unsigned int id) {
	int i;
	// printf("Get records!\n");
	getRecords();
	if (!records) return 1;
	// printf("start check!\n");
	for(i = 0; i < records->size; i++) {
		// printf("checking...\n");
		// printf("no: %d, curID: %u\n", i, (records->r)[i].id);
		if ((records->r)[i].id == id) {
			printf("[ID ERROR]ID IS EXIST.\n");
			return 0;
		}
	}
	return 1;
}

int checkName(char *name) {
	int i;
	for (i = 0; i < strlen(name); i++) {
		if ((name[i] >= 'a' && name[i] <= 'z') ||
			(name[i] >= 'A' && name[i] <= 'Z')) {
			if (name[i] >= 'a' && name[i] <= 'z') {
				if (i == 0) name[0] -= 'a' - 'A';
			}
			else {
				if (i > 0) name[i] += 'a' - 'A';
			}
		}
		else {
			printf("[NAME ERROR]ILLEGAL CHARACTER.\n");
			return 0;
		}
	}
	return 1;
}

int checkHtel(char *htel) {
	int i, flag = 0;
	if (strlen(htel) < 11) {
		printf("[HTEL ERROR]WRONG LENGTH!\n");
		return 0;
	}
	for (i = 0; i < strlen(htel); i++) {
		if (!flag && i >= 4) {
			printf("[HTEL ERROR]WRONG FORMAT!\n");
			return 0;
		}
		if (htel[i] == '-') {
			if (flag) {
				printf("[HTEL ERROR]WRONG FORMAT!\n");
				return 0;
			}
			if (i == 2 || i == 3) flag = 1;
			continue;
		}
		if (!(htel[i] >= '0' && htel[i] <= '9')) {
			printf("[HTEL ERROR]WRONG NUMBER!\n");
			return 0;
		}
	}
	return 1;
}

int checkTel(char *tel) {
	int i;
	char *prefix[4] = {"138", "130", "133", "131"};
	if (strlen(tel) < 11) {
		printf("[TEL ERROR]WRONG LENGTH!\n");
		return 0;
	}
	for (i = 0; i < 4; i++) {
		if (!strncmp(prefix[i], tel, 3)) return 1;
	}
	printf("[TEL ERROR]WRONG NUMBER!\n");
	return 0;
}

void strResize(char *buf, char *str, size_t size) {
	int strSize;
	memset(str, 0, size + 1);
       	strSize = strlen(buf)-1 > size ? size : strlen(buf)-1;
        strncpy(str, buf, strSize);
}

void readIgnore(int number) {
	char ch;
	do {
		ch = getc(stdin);
		// printf("[number:%d-%d]\n", number, ch);
	} while((number&&(ch < '0' || ch > '9'))||(!number&&(ch != '\n')));
	if (number) ungetc(ch, stdin);
}

record* input() {
	unsigned int id;
	char ch;
	size_t *size = (size_t *) malloc(sizeof(size_t));
	char **buf_ptr = (char **) malloc(sizeof(char*));
	
	record* r = (record*) malloc(sizeof(record));
	memset(r, 0, sizeof(record));

	fputs("\t- Please input your id: ", stdout);
	readIgnore(1);
	fscanf(stdin, "%u", &(r->id));
	readIgnore(0);
	fprintf(stdout, "# Your id: %u\n", r->id);
	
	*size = 0;
	*buf_ptr = NULL;
	
	fputs("\t- Please input your name: ", stdout);
	getline(buf_ptr, size, stdin);
	strResize(*buf_ptr, r->name, 7);
	fprintf(stdout, "# Your name: %s\n", r->name);

	fputs("\t- Please input your home telephone number: ", stdout);
	getline(buf_ptr, size, stdin);
	strResize(*buf_ptr, r->htel, 11);
	fprintf(stdout, "# Your home telephone number: %s\n", r->htel);

	fputs("\t- Please input your telephone number: ", stdout);
	getline(buf_ptr, size, stdin);
	strResize(*buf_ptr, r->tel, 11);
	fprintf(stdout, "# Your telephone number: %s\n", r->tel);
	
	return r;
}

int randdat(record *r) {
	int error = 0;
	if (!checkId(r->id)) error = 1;
	if (!checkName(r->name)) error = 1;
	if (!checkHtel(r->htel)) error = 1;
	if (!checkTel(r->tel)) error = 1;
	return !error;
}

void save(record* r) {
	FILE *fp;

	if ((fp = fopen("./user.dat", "r")) == NULL) {
		if ((fp = fopen("./user.dat", "w+")) == NULL)
			err_exit("Create file");
		if ((fprintf(fp,
			"%-10s\t%-7s\t%-11s\t%-11s",
			title[0], title[1], title[2], title[3])) == 0) {
			err_exit("Add title");
		}
	}
	else {
		if ((fp = freopen("./user.dat", "a+", fp)) == NULL)
			err_exit("Open file");
	}
	if ((fprintf(fp,
		"\n%010u\t%-7s\t%11s\t%11s",
		r->id, r->name, r->htel, r->tel)) == 0) {
		err_exit("Write message");
	}

	fclose(fp);
}

int ascname(const void *p1, const void *p2) {
	return strcmp(((record *)p1)->name, ((record *)p2)->name);
}

int descname(const void *p1, const void *p2) {
	return strcmp(((record *)p2)->name, ((record *)p1)->name);
}

list* mysort() {
	char ch;

	fputs("Sorting data in ascending order (1) or in a descending order (0) ? ", stdout);
	ch = fgetc(stdin);
	while(fgetc(stdin) != '\n') ;
	
	if (getRecords()) {
		switch(ch) {
			case '1':
				qsort(records->r, records->size, sizeof(record), ascname);	
				break;
			case '0':
				qsort(records->r, records->size, sizeof(record), descname);
				break;
			default:
				return NULL;
		}
	}
	return records; 
}

void output(record* list, int size) {
	int i;
	fprintf(stdout,
		"%-10s\t%-7s\t%-11s\t%-11s\n",
		title[0], title[1], title[2], title[3]
	);
	for(i = 0; i < size; i++) {
                printf("%010u\t%-7s\t%11s\t%11s\n",
			list[i].id,
			list[i].name,
			list[i].htel,
			list[i].tel
		);
        }
}
