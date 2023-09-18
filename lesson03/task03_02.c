#include <stdio.h>

int main() {
	unsigned long n;
	scanf("%lu", &n);

	unsigned long i = 0;
	while (i < n * n) {
		for (unsigned long j = 1; j <= n; j++) {
			printf("%lu\t", i);
			i++;
		}
		printf("\n");
	}
	return 0;
}
