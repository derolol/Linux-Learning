#include "../ch8.h"

// 编译时 gcc test.c -ldl -o test
// -ldl dynamic load

int main()
{
	int n, *array;
	int ch;
	// int sum;

	void *fpt = dlopen("./libdlib.so", RTLD_NOW);
	if (!fpt) {
		printf("Dlopen failed!\n");
		exit(1);
	}

	/*
	void (*fp)(void) = dlsym(fpt, "dynamic_lib_fun_call");
	if (!fp) {
		printf("Dlsym Failed!\n");
		exit(1);
	}

	void (*getSum)(int a, int b) = dlsym(fpt, "getSum");
	if (!getSum) {
		printf("Dlsym Failed!\n");
		exit(1);
	}
	

	fp();
	sum = getSum(a, b);

	*/


	int (*input)(int **array) = dlsym(fpt, "input");
	if (!input) err_exit("Input fun");
	void (*sort)(int *array, int n) = dlsym(fpt, "sort");
	if (!sort) err_exit("Sort fun");
	void (*randInput)(int **arr, int n) = dlsym(fpt, "randInput");
	void (*output)(int *array, int n) = dlsym(fpt, "output");
	if (!output) err_exit("Output fun");

	array = (int *)malloc(sizeof(int *));
	printf("Rand(1) or Input?(0)");
	scanf("%d", &ch);
	if (!ch) {
		n = input(&array);
	}
	else {
		printf("Please input the length: ");
		scanf("%d", &n);
		randInput(&array, n);
		printf("Rand list: ");
		output(array, n);
	}
	sort(array, n);
	output(array, n);


	dlclose(fpt);
	
	return 0;
}
