#include <stdio.h>

unsigned int dividers_count(unsigned int n) {
	if (n < 0) {
		return -1;
	}
	unsigned int count = 2;
	for (int d = 2; d < n; d++) {
		if (n % d == 0) {
			count++;
		}
	}
	return count;
}

int main() {
	unsigned int n;
	scanf("%u", &n);
	unsigned int d_count = dividers_count(n);
	if (d_count < 0) {
		printf("Error!\n");
	} else {
		printf("Count of dividers %u is %u\n", n, d_count);
	}
	return 0;
}
