#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long draw_field(unsigned long n, unsigned long x, unsigned long y, unsigned long count_food, unsigned long *food) {
	for (unsigned long i = 0; i < n; i++) {
		for (unsigned long j = 0; j < n; j++) {
			int is_food = 0;
			for (unsigned long k = 0; k < n - 1; k += 2) {
				if (i == food[k] && j == food[k + 1]) {
					is_food = 1;
					if (i == y && j == x) {
						count_food--;
						printf("P\t");
						food[k] = -1;
						food[k + 1] = -1;
					} else {
						printf("*\t");
					}
				}
			}
			if (is_food) continue;
			if (i == y && j == x) {
				printf("P\t");
			} else {
				printf(".\t");
			}
		}
		printf("\n");
	}
	return count_food;
}

int main() {
	srand(time(NULL));
	unsigned long n;
	scanf("%lu", &n);
	unsigned long *food = calloc(n, sizeof(unsigned long));
	unsigned long count_food;
	count_food = n / 2;
	for (unsigned long i = 0; i < n; i++) {
		food[i] = rand() % n;

	}
	if (n < 2) {
		printf("Error!\n");
	} else {
		unsigned long x = 0, y = 0, score = 0;
		count_food = draw_field(n, x, y, count_food, food);
		while (count_food > 0) {
			unsigned short move;
			printf("Enter move ");
			scanf("%hu", &move);
			if (move == 4) {
				x = (x - 1 + n) % n;
			} else if (move == 6) {
				x = (x + 1) % n;
			} else if (move == 5) {
				y = (y + 1) % n;
			} else if (move == 8) {
				y = (y - 1 + n) % n;
			} else {
				printf("Incorrect move!\n");
				return 0;
			}
			score++;
			count_food = draw_field(n, x, y, count_food, food);
		}
		printf("You win! You score %lu\n", score);
	}
	return 0;
}
