#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void *a, const void *b) {
	long long x = *(const long long*)a;
	long long y = *(const long long*)b;
	if (x < y) return -1;
	if (x > y) return 1;
	return 0;
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	long long *v = (long long*)malloc(sizeof(long long) * (n + 1));
	for (int i = 1; i <= n; ++i) scanf("%lld", &v[i]);

	long long *pref = (long long*)malloc(sizeof(long long) * (n + 1));
	pref[0] = 0;
	for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + v[i];

	long long *u = (long long*)malloc(sizeof(long long) * (n + 1));
	for (int i = 1; i <= n; ++i) u[i] = v[i];
	qsort(u + 1, n, sizeof(long long), cmp_ll);

	long long *pref_u = (long long*)malloc(sizeof(long long) * (n + 1));
	pref_u[0] = 0;
	for (int i = 1; i <= n; ++i) pref_u[i] = pref_u[i-1] + u[i];

	int m; scanf("%d", &m);
	while (m--) {
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		if (type == 1) {
			printf("%lld\n", pref[r] - pref[l-1]);
		} else {
			printf("%lld\n", pref_u[r] - pref_u[l-1]);
		}
	}

	free(v); free(pref); free(u); free(pref_u);
	return 0;
}
