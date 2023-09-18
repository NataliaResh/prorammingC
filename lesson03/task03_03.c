#include <stdio.h>

int main() {
	unsigned long n;
	scanf("%lu", &n);
	unsigned long k = 0;
	for (unsigned long i = 1; k <= (n * (n + 1)) / 2 - 1; i++) {
		for (unsigned long j = 1; j <= i; j++) {
			printf("%lu ", k);
			k++;
		}
		printf("\n");
	}
	return 0;
}
