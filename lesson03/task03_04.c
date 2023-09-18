#include <stdio.h>
#include <math.h>

int isPrime(unsigned long long x) {
	for (unsigned long long i = 2; i <= x/2 + 1; i++){
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	unsigned long long n;
	scanf("%llu", &n);
	if (n < 2) {
		printf("Error!\n");
	} else {
		if (isPrime(n)) {
			printf("Число %llu простое\n", n);
		} else {
			printf("Число %llu не простое\n", n);
		}
	}
	return 0;
}

