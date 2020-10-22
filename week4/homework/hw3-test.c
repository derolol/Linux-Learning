/*
 * 2.10-10
 * 设某个文件含n个记录，文件的第一个字（4字节）给出记录的总个数n，
 * 随后的n个字给出各个记录的长度（字节数），剩余部分则由各个记录组成。
 * 编写一个根据文件指针和记录编号（从1开始编号）读取第k个记录的函数。
 */

#include <math.h>
#include "ch3.h"

typedef struct record {
	long no;
	long length;
	long pos;
	struct record* next;
} Record;

long getLong(char* s) {
	int i;
	long res = 0;
	for (i = 3; i >= 0; i--) {
		// printf("%x\n", s[i]);
		res += (res << 8) + s[i];
		// printf("%ld\n\n", res);
	}
	return res;
}

void readK(char* buffer, int size, FILE* fp, int no) {
	int i;
	long res;
	long n, f_pointer = 4, i_pointer = 0;
	char buf[4];
	Record* head = NULL;
	Record* cur = NULL;

	fseek(fp, 0, SEEK_SET);
	memset(buffer, 0, size);

	fread(buf, 4, 1, fp);
	n = getLong(buf);
	printf("Number of items: %ld\n", n);

	if (no > n) err_exit("Read file");

	i_pointer = 4 + (n << 2);

	for (i = 1; i < no + 1; i++) {
		// printf("ipointer: %ld fpointer: %ld\n\n", i_pointer, f_pointer);

		fseek(fp, f_pointer, SEEK_SET);
		fread(buf, 4, 1, fp);
		n = getLong(buf);
		// printf("item size: %ld", n);

		Record* r = (Record*)malloc(sizeof(Record));	
		r->no = i;
		r->length = n;
		r->pos = i_pointer;
		r->next = NULL;
				
		if (!head) head = r;
		if (cur) cur->next = r;
		cur = r;
				
		f_pointer += 4;
		i_pointer += n;

		// printf("第%d项的长度为: %ld\n", i+1, getLong(buf));
		// printf("下次读取的指针位置距离文件头的距离为: %ld\n", point);
	}

	cur = head;
	for (i = 0; i < no-1; i++) {
		// printf("no: %ld\n", cur->no);
		// printf("length: %ld\n", cur->length);
		// printf("pos: %ld\n", cur->pos);
		cur = cur->next;
	}

	printf("当前指向第%ld项，文件的长度%ld为，地址为%ld\n", cur->no, cur->length, cur->pos);


	
	fseek(fp, cur->pos, SEEK_SET);

	res = size > cur->length ? cur->length : size;
	printf("打算读%ld个字节\n", res);

	res = fread(buffer, res, 1, fp);
	printf("已读%ld个字节\n", res);

	printf("读取的内容为%s\n", buffer);
}

int main() {
	int i;
	char buffer[1024];
	FILE* fp;
	fp = fopen("test.dat", "r");
	for (i = 1; i < 5; i++) readK(buffer, sizeof(buffer), fp, i);
	return 0;
}
