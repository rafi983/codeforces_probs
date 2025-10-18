#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void *a, const void *b) {
	long long lhs = *(const long long *)a;
	long long rhs = *(const long long *)b;
	if (lhs < rhs) return -1;
	if (lhs > rhs) return 1;
	return 0;
}

int main(void) {
	int n;
	long long k;
	if (scanf("%d %lld", &n, &k) != 2) {
		return 0;
	}

	long long *h = (long long *)malloc((size_t)n * sizeof(long long));
	if (!h) {
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (scanf("%lld", &h[i]) != 1) {
			free(h);
			return 0;
		}
	}

	qsort(h, (size_t)n, sizeof(long long), cmp_ll);

	long long slices = 0;
	long long cur_cost = 0; /* cubes used in current slice */
	long long cumulative = 0; /* towers affected in current band */

	int i = n - 1;
	while (i >= 0) {
		long long height = h[i];
		int j = i;
		while (j >= 0 && h[j] == height) {
			--j;
		}
		cumulative += (long long)(i - j);
		if (j < 0) {
			break;
		}
		long long next_height = h[j];
		long long delta = height - next_height;
		while (delta > 0) {
			if (cur_cost == k) {
				++slices;
				cur_cost = 0;
			}
			long long remaining = k - cur_cost;
			long long max_layers = remaining / cumulative;
			if (max_layers == 0) {
				++slices;
				cur_cost = 0;
				continue;
			}
			long long take = delta < max_layers ? delta : max_layers;
			cur_cost += take * cumulative;
			delta -= take;
		}
		i = j;
	}

	if (cur_cost > 0) {
		++slices;
	}

	printf("%lld\n", slices);

	free(h);
	return 0;
}
