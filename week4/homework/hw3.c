/*
 * 2.10-10
 * 设某个文件含n个记录，文件的第一个字（4字节）给出记录的总个数n，
 * 随后的n个字给出各个记录的长度（字节数），剩余部分则由各个记录组成。
 * 编写一个根据文件指针和记录编号（从1开始编号）读取第k个记录的函数。
 */

#include <math.h>
#include "ch3.h"

// 定义存储记录信息的结构体
typedef struct record {
	long no;
	long length;
	long pos;
	struct record* next;
} Record;

// 获取4字节长度的长整型值
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

// 将文件指针fp指向的文件的第no项记录的内容读入buffer缓冲区中
// 最大的读入字节数量为size
long readK(char* buffer, int size, FILE* fp, int no) {
	int i;
	long res;
	long n, f_pointer = 4, i_pointer = 0;
	char buf[4];
	Record* head = NULL;
	Record* cur = NULL;

	// 将文件的指针定位到文件头，初始化缓冲区
	fseek(fp, 0, SEEK_SET);
	memset(buffer, 0, size);

	// 读取文件头的4字节，获取文件的总记录数
	fread(buf, 4, 1, fp);
	n = getLong(buf);
	printf("Number of items: %ld\n", n);

	// 如果要读取的记录编号大于总记录数，则视为非法读取
	if (no > n) err_exit("Read file");

	// 可得知当前文件内容的开始位置与文件头的字节间隔数
	i_pointer = 4 + (n << 2);

	for (i = 1; i < no + 1; i++) {
		// 将文件指针定位到描述记录长度的字节前
		fseek(fp, f_pointer, SEEK_SET);
		
		fread(buf, 4, 1, fp);
		// sscanf(buf, "%ld", &n);
		n = getLong(buf);
		// fscanf(fp, "%ld", &n);

		// 初始化记录结构体的信息
		Record* r = (Record*)malloc(sizeof(Record));	
		r->no = i;
		r->length = n;
		r->pos = i_pointer;
		r->next = NULL;
		
		// 如果头指针为空，则让头指针指向新分配的结构体指针		
		if (!head) head = r;
		// 如果当前的结构体指针不为空，则让当前指针的下一个指向新分配指针
		if (cur) cur->next = r;
		// 让当前指针指向新分配指针
		cur = r;
				
		// 描述记录长度的指针后移4字节
		f_pointer += 4;
		// 记录内容指针后移当前记录的长度个字节
		i_pointer += n;
	}

	// 从首部往后查找第no个记录的信息
	cur = head;
	for (i = 0; i < no-1; i++) {
		cur = cur->next;
	}
	printf("当前指向第%ld项，文件的长度%ld为，地址为%ld\n", cur->no, cur->length, cur->pos);

	// 将文件指针移动到该记录开始的位置
	fseek(fp, cur->pos, SEEK_SET);

	// 计算可以读取的字节
	res = size > cur->length ? cur->length : size;
	printf("打算读%ld个字节\n", res);

	if (fread(buffer, res, 1, fp)) {
		printf("已读%ld个字节\n", res);
		printf("读取的内容为%s\n", buffer);
		return res;
	}
	else err_exit("Read content of record");
}

int main(int argc, char* argv[]) {
	long no;
	char buffer[1024];
	FILE* fp;
	
	if (argc < 2) err_exit("Read file name");

	fp = fopen(argv[1], "r");
	if (!fp) err_exit("Open file");
	
	do {
		fprintf(stdout, "Please input the record number: ");
		fscanf(stdin, "%ld", &no);
		getchar();
		readK(buffer, sizeof(buffer), fp, no);
	} while (y_or_n_ques("Do you want to continue?"));

	return 0;
}
