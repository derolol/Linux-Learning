#include "ch3.h"

int main() {
	float fl = 0.1;
	double dl = 0.1;
	char* flp = (char*) &fl;
	char* dlp = (char*) &dl;

	printf("MIN INT: %d\n", 0x80000000);
	printf("MAX INT: %d\n", 0x7FFFFFFF);

	*flp = 0xFF;
	*(flp+1) = 0xFF;
	*(flp+2) = 0x7F;
	*(flp+3) = 0x7F;
	printf("MAX FLOAT: %.100g\n", fl);
	
	*flp = 0x00;
        *(flp+1) = 0x00;
        *(flp+2) = 0x80;
        *(flp+3) = 0x00;
        printf("MIN FLOAT: %.100g\n", fl);

	*dlp = 0xFF;
        *(dlp+1) = 0xFF;
        *(dlp+2) = 0xFF;
        *(dlp+3) = 0xFF;
	*(dlp+4) = 0xFF;
	*(dlp+5) = 0xFF;
	*(dlp+6) = 0xEF;
	*(dlp+7) = 0x7F;
        printf("MIN DOUBLE: %.200g\n", dl);
	
	*dlp = 0x00;
        *(dlp+1) = 0x00;
        *(dlp+2) = 0x00;
        *(dlp+3) = 0x00;
        *(dlp+4) = 0x00;
        *(dlp+5) = 0x00;
        *(dlp+6) = 0x10;
        *(dlp+7) = 0x00;
        printf("MIN DOUBLE: %.200g\n", dl);

	return 0;
}
