#include "ch6.h"

int main(int argc, char *argv[]) {
	int a, b;
	if (argc != 3) err_exit("Argument number");
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("%d\n", a+b);
	//for (int i = 0; i < argc; i++ ){
	//	printf("argv[%d] : %s\n", i, argv[i]);
	//}
	return 0;

}
