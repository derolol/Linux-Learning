#include "../ch6.h"
#define N 10

// 编译的时候全局变量的内存地址和宽度就已经确定了
// 存储在内存的全局数据区，而且地址是连续分配的
// []是下标运算符，将首地址加上偏移量的地址计算出来
// a[N]的地址和i的地址是相同的，所以对a[N]和对i操作都是相同的

int a[N], i;
int main() {
	for (i = 0; i < N; i ++) {
		a[i] = i+1;
	}

	for (i = 0; i < N; i++) {
		printf("&a[%d] = %p\n", i, &a[i]);
	}
	printf("&a[%d] = %p\n", N, &a[N]);
	printf("&i = %p\n", &i);

	printf("\n执行 a[N] = 123456789\n");
	a[N] = 123456789;
	printf("i = %d\n", i);
	printf("a[N] = %d\n", a[N]);

	printf("\n执行 i = 9999\n");
	i = 9999;
	printf("i = %d\n", i);
	printf("a[N] = %d\n", a[N]);

	return 0;
}
