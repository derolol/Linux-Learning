#include "../ch8.h"

void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called!\n");
}

int getSum(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a+b);
	return a+b;
}

int input(int **arr) {
	int n, i;
	printf("Please input the length of array: ");
	scanf("%d", &n);
	*arr = (int *)malloc(sizeof(int) * n);	
	printf("Please input the number: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &(*arr)[i]);
	}
	return n;
}

void randInput(int **arr, int n) {
	int i;
	srand((unsigned int)time(NULL));
	*arr = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		(*arr)[i] = rand()%100;
	}
}

int compare(const void *p1, const void *p2) {
	int *a = (int *)p1;
	int *b = (int *)p2;
	// printf("Cmp %d and %d\n", *a, *b);
	return *a - *b;
}

void sort(int *array, int n) {
	// printf("Start Sort! n = %d \n", n);
	qsort(array, n, sizeof(int), compare);
	// printf("End Sort!\n");
}

void output(int *array, int n) {
	int i;
	printf("Output: ");
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
