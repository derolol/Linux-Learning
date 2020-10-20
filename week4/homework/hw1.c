/*
 * 1.9-6
 * 查看你的系统的头文件limits.h。
 * 系统相关的静态限制值有哪些？
 * 它们的值各为多少？
 * 特别的，整数类型、浮点类型和双精度类型的最大、最小值各为多少？
 */

#include <limits.h>
#include <float.h>
#include "ch3.h"

int main() {
	int fd, state;
	char buffer[1024];
	
	// 输出预处理得到的文本文件中limits.h头文件的地址
	printf("[Find out the path of limits.h]\n\n");
	if ((fd = open("hw1.i", O_RDONLY, 0644)) != -1) {
		while(read(fd, buffer, sizeof(buffer))) {
			state = fwrite(buffer, sizeof(buffer), 1, stdout);
			if (state == -1) err_exit("Write file");
		}
	}
	else err_exit("Open file");
	
	// 打印limits.h头文件中的静态限制值
	printf("\n\n[Static value in limits.h]\n\n");

	// 每个字符所占的位数
	printf("CHAR_BIT: %d\n", CHAR_BIT);
	// 多字节字符的最大长度
	printf("MB_LEN_MAX: %d\n", MB_LEN_MAX);
	// 带符号字符的最大/小值
	printf("SCHAR_MIN: %d\n", SCHAR_MIN);
	printf("SCHAR_MAX: %d\n", SCHAR_MAX);
	// 无符号字符的最大值
	printf("UCHAR_MAX: %d\n", UCHAR_MAX);
	// 字符型变量的最大/小值
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	// 短型变量的最大/小值
	printf("SHRT_MIN: %d\n", SHRT_MIN);
	printf("SHRT_MAX: %d\n", SHRT_MAX);
	// 无符号短型变量的最大/小值
	printf("USHRT_MAX: %d\n", USHRT_MAX);
	// 整型变量的最大/小值
	printf("INT_MIN: %d\n", INT_MIN);
	printf("INT_MAX: %d\n", INT_MAX);
	// 无符号整型的最大值
	printf("UINT_MAX: %u\n", UINT_MAX);
	// 长整型的最大/小值
	printf("LONG_MIN: %ld\n", LONG_MIN);
	printf("LONG_MAX: %ld\n", LONG_MAX);
	// 无符号长整型的最大值
	printf("ULONG_MAX: %lu\n", ULONG_MAX);
	// 长长整型的最大/小值
	printf("LLONG_MIN: %lld\n", LLONG_MIN);
	printf("LLONG_MAX: %lld\n", LLONG_MAX);
	// 无符号长长整型的最大值
	printf("ULLONG_MAX: %llu\n", ULLONG_MAX);

	// 未定义的常量
	// printf("LONG_LONG_MIN: %d\n", LONG_LONG_MIN);
	// printf("LONG_LONG_MAX: %d\n", LONG_LONG_MAX);
	// printf("ULONG_LONG_MAX: %d\n", ULONG_LONG_MAX);
	// printf("CHAR_WIDTH: %d\n", CHAR_WIDTH);
	// printf("SCHAR_WIDTH: %d\n", SCHAR_WIDTH);
	// printf("UCHAR_WIDTH: %d\n", UCHAR_WIDTH);
	// printf("SHRT_WIDTH: %d\n", SHRT_WIDTH);
	// printf("USHRT_WIDTH: %d\n", USHRT_WIDTH);
	// printf("INT_WIDTH: %d\n", INT_WIDTH);
	// printf("UINT_WIDTH: %d\n", UINT_WIDTH);
	// printf("LONG_WIDTH: %d\n", LONG_WIDTH);
	// printf("ULONG_WIDTH: %d\n", ULONG_WIDTH);
	// printf("LLONG_WIDTH: %d\n", LLONG_WIDTH);
	// printf("ULLONG_WIDTH: %.0lf\n", ULLONG_WIDTH);

	// 整型、浮点型、双精度浮点型变量的最大/小值 
	printf("\n\n整型最小值: %d\n", INT_MIN);
	printf("整型最大值: %d\n", INT_MAX);
	printf("浮点型最小正值: %e\n", FLT_MIN);
	printf("浮点型最大正值: %e\n", FLT_MAX);
	printf("浮点型的最小值: %e\n", -FLT_MAX);
	printf("双精度最小正值: %e\n", DBL_MIN);
	printf("双精度最大正值: %e\n", DBL_MAX);
	printf("双精度的最小值: %e\n", -DBL_MAX);

	return 0;
}
