#include <stdio.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) {
		return 0;
	}

	while (t--) {
		long long x, n;
		if (scanf("%lld %lld", &x, &n) != 2) {
			return 0;
		}

		long long limit = x / n; /* g cannot exceed this or sum would drop below n */
		long long best = 1;

		for (long long i = 1; i * i <= x; ++i) {
			if (x % i == 0) {
				if (i <= limit && i > best) {
					best = i;
				}
				long long pair = x / i;
				if (pair <= limit && pair > best) {
					best = pair;
				}
			}
		}

		printf("%lld\n", best);
	}

	return 0;
}
