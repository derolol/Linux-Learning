#include "my.h"

int main() {
	record *r = input();
	save(r);
	list *records = mysort();
	if (records)
		output(records->r, records->size);
	else printf("NULL");
	return 0;
}
