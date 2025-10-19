#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
	int x = *(const int *)a;
	int y = *(const int *)b;
	return (x > y) - (x < y);
}

int main(void) {
	int n;
	long long l;
	if (scanf("%d %lld", &n, &l) != 2) return 0;
	int *a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp_int);

	double max_gap = 0.0;
	// Edges: from 0 to first, and last to l
	if (a[0] > max_gap) max_gap = (double)a[0];
	if ((double)l - a[n-1] > max_gap) max_gap = (double)l - a[n-1];
	// Middle gaps
	for (int i = 1; i < n; ++i) {
		double gap = (a[i] - a[i-1]) / 2.0;
		if (gap > max_gap) max_gap = gap;
	}

	printf("%.10f\n", max_gap);
	free(a);
	return 0;
}
