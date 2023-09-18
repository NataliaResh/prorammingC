#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned long L, R;
	scanf("%lu", &L);
	scanf("%lu", &R);
	if (L > R) {
		printf("Error!");
	} else {
		if (L < 100000) {
			L = 100000;
		}
		for (unsigned long i = L; i < R && i < 1000000; i++) {
			if (i / 100000 + i / 10000 % 10+ i / 1000 % 10 == i / 100 % 10 + i / 10 % 10 + i %  10) {
				printf("%lu ", i);
			}
		}
		printf("\n");
	}
	return 0;
}