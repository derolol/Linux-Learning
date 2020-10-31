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
        records->r = (record *) malloc(sizeof(record *) * (records->size));

        fseek(fp, 43, SEEK_SET);
        while(!feof(fp)) {
                fscanf(fp,
			"%u%s%s%s",
			&((records->r)[cur].id),
			(records->r)[cur].name,
			(records->r)[cur].htel,
			(records->r)[cur].tel);
		cur ++;
	}
	printf("4\n");
	printf("%p\n", fp);
	if (!fp) printf("NULL!\n");
	fclose(fp);
	printf("5\n");
	return records;
}

int checkId(unsigned int id) {
	int i;
	printf("Get records!\n");
	getRecords();
	printf("start check!\n");
	for(i = 0; i < records->size; i++) {
		printf("checking...\n");
		printf("no: %d, curID: %u\n", i, (records->r)[i].id);
		if ((records->r)[i].id == id) {
			printf("ID IS EXIST.\n");
			return 0;
		}
	}
	return 1;
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
		printf("[number:%d-%d]\n", number, ch);
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

	do {
		fputs("Please input your id: ", stdout);
		readIgnore(1);
		fscanf(stdin, "%u", &id);
		readIgnore(0);
		printf("Finish once!\n");
	} while(checkId(id));
	r->id = id;
	
	*size = 0;
	*buf_ptr = NULL;
	
	fputs("Please input your name: ", stdout);
	getline(buf_ptr, size, stdin);
	strResize(*buf_ptr, r->name, 7);

	fputs("Please input your telephone number: ", stdout);
	getline(buf_ptr, size, stdin);
	strResize(*buf_ptr, r->htel, 11);

	fputs("Please input your phone number: ", stdout);
	getline(buf_ptr, size, stdin);
	strResize(*buf_ptr, r->tel, 11);
	
	return r;
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
