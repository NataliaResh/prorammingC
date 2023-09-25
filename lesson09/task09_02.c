#include <stdio.h>
#include <stdlib.h>

void checkNull(void *ptr) {
	if (ptr == NULL) {
		printf("Out of memory!\n");
		exit(0);
	}
}

int* findSubArr(int *arr1, size_t len1, int *arr2, size_t len2) {
	size_t start = 0, i = 0;
	while (start + len2 <= len1) {
		if (i == len2) {
			return &(arr1[start]);
		}
		if (arr1[start + i] == arr2[i]) {
			i++;
		} else {
			i = 0;
			start = start + 1;
		}
	}
	return NULL;
}

int main() {
	size_t len1, len2;
	scanf("%zu", &len1);
	int *arr1 = (int*) malloc(len1 * sizeof(int));
	checkNull(arr1);
	for (size_t i = 0; i < len1; i++) {
		scanf("%d", &arr1[i]);
	}
	scanf("%zu", &len2);
	int *arr2 = (int*) malloc(len2 * sizeof(int));
	checkNull(arr2);
	for (size_t i = 0; i < len2; i++) {
		scanf("%d", &arr2[i]);
	}
	int *ans = findSubArr(arr1, len1, arr2, len2);
	if (ans == NULL) {
		printf("Subarray is not found!\n");
	} else {
		printf("%ld\n", ans - &arr1[0]);
	}
	return 0;
}
