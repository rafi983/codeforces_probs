#include <stdio.h>

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	int a[1005];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int min_idx = 0, max_idx = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[min_idx]) min_idx = i;
		if (a[i] > a[max_idx]) max_idx = i;
	}

	int tmp = a[min_idx];
	a[min_idx] = a[max_idx];
	a[max_idx] = tmp;

	for (int i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", a[i]);
	}
	putchar('\n');
	return 0;
}
