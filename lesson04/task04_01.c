#include <stdio.h>
#include <math.h>

int isPrime(unsigned long long x) {
	for (unsigned long long i = 2; i <= x/2; i++){
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
		return 0;
	}
	for (unsigned long long i = 2; i <= n; i++){
		if (isPrime(i)) {
			printf("%llu ", i);
		}
	}
	printf("\n");
	return 0;
}
