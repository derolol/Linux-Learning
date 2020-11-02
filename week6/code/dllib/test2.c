#include "../ch6.h"

int main(int argc, char *argv[]) {
	int n;
	void *dlib = dlopen("./libdlib.so", RTLD_NOW);
	if (!dlib) {
		printf("dlopen failed!\n");
		exit(-1);
	}
	void(*dfunc) (void) = dlsym(dlib, "dynamic_lib_call");
	void(*dsum) (int) = dlsym(dlib, "dsum");

	if (!dfunc) {
		printf("dfunc is failed!\n");
		exit(-1);
	}
	if (!dsum) {
		printf("dsum id failed!\n");
	}

	dfunc();
	
	if (argc != 2) err_exit("Argument input");

	n = atoi(argv[1]);
	dsum(n);
	
	dlclose(dlib);

	return 0;
}
