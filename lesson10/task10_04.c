#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <setjmp.h>

jmp_buf buf;

void exitOrJmp(int errorCode, jmp_buf buf) {
	if (buf == NULL) {
		exit(errorCode);
	}
	longjmp(buf, errorCode);
}


int s2i(const char *str, char base, jmp_buf buf) {
	if (base > 16 || base < 2) {
		exitOrJmp(1, buf);
	}
	int ans = 0;
	const char *ptr = str;
	int isNegative = 0;
	if (*ptr == '-') {
		isNegative = 1;
		ptr++;
	}
	for (; *ptr != '\0'; ptr++) {
		if (ans > INT_MAX / base) {
			exitOrJmp(2, buf);
		}
		ans *= base;
		char symbol = *ptr;
		int digit = INT_MAX;
		if (symbol >= '0' && symbol <= '9') {
			digit = symbol - '0';
		} else if (symbol >= 'A' && symbol <= 'F') {
			digit = symbol - 'A' + 10;
		}
		if (digit >= base) {
			exitOrJmp(3, buf);
		} else if (ans > INT_MAX - digit) {
			exitOrJmp(2, buf);
		} else {
			ans += digit;
		}
	}
	if (isNegative) {
		ans *= -1;

	}
	return ans;
}

int main() {
	int errCode = setjmp(buf);
	if (!errCode) {
		int n = s2i("12AD", 16, buf);
		printf("%d\n", n);
	} else if (errCode == 1) {
		printf("Incorect base\n");
	} else if (errCode == 2) {
		printf("Overflow\n");
	} else if (errCode == 3) {
		printf("Incorect symbols\n");
	}
	return 0;
}
