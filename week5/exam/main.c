#include "my.h"

int main() {
	int exit = 0;
	char choice;
	record *r = NULL;
	list *records = NULL;

	printf("- Welcome to Telephone Directory -");
	do {
		printf("\n---------------------------------\n");
		printf(" 1. Add Record.\n");
		printf(" 2. Read Telephone Directory.\n");
		printf(" 3. Exit.\n");
		printf("---------------------------------\n");

		printf("# Please enter your choice: ");
		choice = getc(stdin);
		getc(stdin);

		switch(choice-'0') {
			case 1:
				do r = input();
				while(!randdat(r));
				printf("\n# Saving Record!\n");
				save(r);
				printf("\n# New Record!\n");
				output(r, 1);
				break;
			case 2:
				records = mysort();
				if (records)
					output(records->r, records->size);
				break;
			case 3:
				exit = 1;
				break;
			default:
				break;
		}

	} while(!exit);
	
	return 0;
}
