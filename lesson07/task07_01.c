#include <stdio.h>

int main() {
	size_t n = 4;
	int a[n][n];
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; j++) {
			int t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
