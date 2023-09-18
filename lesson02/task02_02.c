#include <stdio.h>

int main(){
	unsigned short year;
	scanf("%hu", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		printf("%u високосный год\n", year);
	} else {
		printf("%u не високосный год\n", year);
	}
	return 0;
}
