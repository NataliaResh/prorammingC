#include <stdio.h>
#include <stdlib.h>

void draw_field(unsigned long n, unsigned long x, unsigned long y) {
	for (unsigned long i = 0; i < n; i++) {
		for (unsigned long j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1) {
				printf("*\t");
			} else if (i == x && j == y) {
				printf("P\t");
			} else {
				printf(".\t");
			}
		}
		printf("\n");
	}
}

int main() {
	unsigned long n;
	scanf("%lu", &n);
	if (n < 2) {
		printf("Error!\n");
	} else {
		unsigned long x = 0, y = 0, score = 0;
		while (x != n - 1 || y != n - 1) {
			draw_field(n, x, y);
			unsigned short move;
			printf("Enter move ");
			scanf("%hu", &move);
			if (move == 4) {
				if (x > 0) {
					x--;
				}
			} else if (move == 6) {
				if (x < n - 1) {
					x++;
				}
			} else if (move == 5) {
				if (y < n - 1) {
					y++;
				}
			} else if (move == 8) {
				if (y > 0) {
					y--;
				}
			} else {
				printf("Incorrect move!\n");
				return 0;
			}
			score++;
		}
		printf("You win! You score %lu\n", score);
	}
	return 0;
}