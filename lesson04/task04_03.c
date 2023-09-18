#include <stdio.h>

unsigned int gcd(unsigned int a, unsigned int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}
	
int main() {
	unsigned int a, b;
	scanf("%u", &a);
	scanf("%u", &b);
	if (a < 1 || b < 1) {
		printf("Error\n");
		return 0;
	}
	printf("GCD(%u, %u) is %u\n", a, b, gcd(a, b));
	return 0;
}