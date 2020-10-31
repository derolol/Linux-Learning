#include "my.h"

int main() {
	// record *r = input();
	// save(r);
	list *records = mysort();
	output(records->r, records->size);
	return 0;
}
