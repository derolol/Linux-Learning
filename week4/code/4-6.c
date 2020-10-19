#include "ch3.h"

/*
 * 利用dup2函数，将标准输出指向文件描述符
 * 使得在用printf函数时输出重定向到该文件
 */

int main() {
	int d1;
	d1 = open("./out.info", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(d1, 1);
	// d1 = dup(STDOUT_FILENO);
	// STDOUT_FILENO = dup(d1);
	
	write(d1, "Hello", 5);
	// printf("Redirect stdout file!\n");
	return 0;
}
