#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
	int T;
	if (scanf("%d", &T) != 1) {
		return 0;
	}

	while (T--) {
		int n;
		if (scanf("%d", &n) != 1) {
			return 0;
		}

		long long *a = (long long *)malloc((size_t)n * sizeof(long long));
		long long *b = (long long *)malloc((size_t)n * sizeof(long long));
		if (!a || !b) {
			free(a);
			free(b);
			return 0;
		}

		for (int i = 0; i < n; ++i) {
			if (scanf("%lld %lld", &a[i], &b[i]) != 2) {
				free(a);
				free(b);
				return 0;
			}
		}

		long long total = 0;
		long long best_start = LLONG_MAX;

		for (int i = 0; i < n; ++i) {
			long long prev_explosion = b[(i - 1 + n) % n];
			long long needed = a[i] > prev_explosion ? a[i] - prev_explosion : 0;
			total += needed;
			long long candidate = a[i] - needed;
			if (candidate < best_start) {
				best_start = candidate;
			}
		}

		printf("%lld\n", total + best_start);

		free(a);
		free(b);
	}

	return 0;
}
