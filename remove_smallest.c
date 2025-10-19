#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
	int x = *(const int *)a;
	int y = *(const int *)b;
	return (x > y) - (x < y);
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		int n;
		if (scanf("%d", &n) != 1) n = 0;
		int a[55];
		for (int i = 0; i < n; ++i) {
			if (scanf("%d", &a[i]) != 1) a[i] = 0;
		}
		qsort(a, n, sizeof(int), cmp_int);
		int ok = 1;
		for (int i = 1; i < n; ++i) {
			if (a[i] - a[i-1] > 1) { ok = 0; break; }
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
