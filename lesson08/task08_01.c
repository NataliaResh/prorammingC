#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void checkNull(void *ptr) {
	if (ptr == NULL) {
		printf("Out of memory\n");
		exit(0);
	}
}

void scanArr(int *arr, size_t len) {
	for (size_t i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}
}

void printArr(int *arr, size_t len) {
	for (size_t i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void revertArr(int *arr, size_t len) {
	size_t half_len = len / 2;
	for (size_t i = 0; i < half_len; i++) {
		int c = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = c;
	}
}

int maxlnArr(int *arr, size_t len) {
	int ans = INT_MIN;
	for (size_t i = 0; i < len; i++) {
		if (arr[i] > ans) {
			ans = arr[i];
		}
	}
	return ans;
}

int findlnArr(int *arr, size_t len, int x) {
	for (size_t i = 0; i < len; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

void extractDigits(int *arr, size_t len, int x) {
	int i = 0;
	while (x > 0) {
		arr[i] = x % 10;
		x /= 10;
		i++;
	}
	revertArr(arr, i);
}

int compareArrays(int *arr1, size_t len1, int *arr2, size_t len2) {
	for (size_t i = 0; i < len1 && i < len2; i++) {
		if (arr1[i] < arr2[i]) {
			return -1;
		}
		if (arr1[i] > arr2[i]) {
			return 1;
		}
	}
	if (len1 < len2) {
		return -1;
	}
	if (len1 > len2) {
		return 1;
	}
	return 0;
}

int main() {
	size_t len1, len2;
	printf("First array's len is ");
	scanf("%zu", &len1);
	int *arr1 = (int*) malloc(len1 * sizeof(int));
	checkNull(arr1);
	scanArr(arr1, len1);
	printf("Second array's len is ");
	scanf("%zu", &len2);
	int *arr2 = (int*) malloc(len2 * sizeof(int));
	checkNull(arr2);
	scanArr(arr2, len2);
	printf("First array:\n");
	printArr(arr1, len1);
	printf("Second array:\n");
	printArr(arr2, len2);
	printf("Reversing first array...\n");
	revertArr(arr1, len1);
	printf("First array:\n");
	printArr(arr1, len1);
	printf("Max in second array is %d:\n", maxlnArr(arr2, len2));
	printf("What number you want to find in first array: ");
	int n;
	scanf("%d", &n);
	int index = findlnArr(arr1, len1, n);
	if (index < 0) {
		printf("%d not found in first array\n", n);
	} else {
		printf("arr1[%d] = %d\n", findlnArr(arr1, len1, n), n);
	}
	printf("Enter x: ");
	int x;
	scanf("%d", &x);
	if (len1 >= 10) {
		printf("Extracting digits of %d in first array...\n", x);
		extractDigits(arr1, len1, x);
		printf("First array:\n");
		printArr(arr1, len1);
	} else if (len2 >= 10) {
		printf("Extracting digits of %d in second array...\n", x);
		extractDigits(arr2, len2, x);
		printf("Second array:\n");
		printArr(arr2, len2);
	}
	printf("first array > second array = %d\n", compareArrays(arr1, len1, arr2, len2));
	free(arr1);
	free(arr2);
	return 0;
}

