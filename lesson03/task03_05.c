#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned long long n;
	scanf("%llu", &n);
	if (n < 2) {
		printf("Error!\n");
	} else {
		int *a = calloc(n + 1, sizeof(int));
		for (unsigned long long i = 2; i <= n; i++) {
			if (a[i] == 0){
				printf("%llu ", i);
				for (unsigned long long j = i * 2; j <= n; j += i) {
					a[j] = 1;
				}
			}
		}
		printf("\n");
		free(a);
	}
	return 0;
}