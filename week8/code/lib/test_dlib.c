#include "../ch8.h"

extern void dynamic_lib_fun_call(void);
extern int getSum(int a, int b);
int main(int argc, char* argv[])
{
	int a, b, sum;
	if (argc != 3) err_exit("Attribute wrong");
	dynamic_lib_fun_call();
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	sum = getSum(a, b);
	printf("Test get number: %d\n", sum);
	return 0;
}
