#include <stdio.h>
#include <stdlib.h>

int** triangleArray(size_t len) {
	int** arr = malloc(len * sizeof(int*));
	for (size_t i = 0; i < len; i++) {
		arr[i] = malloc((i + 1) * sizeof(int));
	}
	return arr;
}

void trianglePascal(int** arr, size_t len) {
	for (size_t i = 0; i < len; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (size_t j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
}

void printPascal(int** arr, size_t len) {
	for (size_t i = 0; i < len; i++) {
		for (size_t j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	size_t len;
	scanf("%zu", &len);
	int** arr = triangleArray(len);
	trianglePascal(arr, len);
	printPascal(arr, len);
	return 0;
}
