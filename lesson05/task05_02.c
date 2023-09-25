#include <stdio.h>

void evilScanf(int *p0, int *p1, int *p2) {
	int n0, n1, n2;
	scanf("%d", &n0);
	scanf("%d", &n1);
	scanf("%d", &n2);
	if (n0 > 0) {
		*p1 = n1;
		*p2 = n2;
	} else {
		*p2 = n0 * n1 * n2 * (*p1) * (*p2);
		*p1 = *p0;
	}
	*p0 = n0;
}
int main() {
	int p0, p1, p2;
	scanf("%d", &p0);
	scanf("%d", &p1);
	scanf("%d", &p2);
	printf("Before evilScanf:\np0 = %d\np1 = %d\np2 = %d\n", p0, p1, p2);
	evilScanf(&p0, &p1, &p2);
	printf("After evilScanf:\np0 = %d\np1 = %d\np2 = %d\n", p0, p1, p2);
	return 0;
}
