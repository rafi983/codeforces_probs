#include <stdio.h>

int main(void) {
	int n, m;
	if (scanf("%d %d", &n, &m) != 2) return 0;

	int a[105], b[105];
	int max_a = 0, min_a = 101;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > max_a) max_a = a[i];
		if (a[i] < min_a) min_a = a[i];
	}

	int min_b = 101;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		if (b[i] < min_b) min_b = b[i];
	}

	int v = max_a;
	if (2 * min_a > v) v = 2 * min_a;

	if (v < min_b) {
		printf("%d\n", v);
	} else {
		printf("-1\n");
	}

	return 0;
}
