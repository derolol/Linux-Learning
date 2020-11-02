#include "ch6.h"

// stack -> first state last call

static void callback1(void)
{
	printf("--------CallBack1--------\n");
}

static void callback2(void)
{
	printf("--------CallBack2--------\n");
}

static void callback3(void)
{
	printf("--------CallBack3--------\n");
}

static void __attribute__ ((destructor)) after_main() {
        printf("--------Destructor-------\n");
}

int main(void) {
	atexit(callback1); // register callback function while exit
	atexit(callback2);
	atexit(callback3);
	printf("--------Main Exit--------\n");
	exit(0); // Clean line buffer and exit
	// _exit(0);  // Force exit
}
