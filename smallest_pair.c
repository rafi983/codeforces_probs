#include <stdio.h>

int main(void) {
	int T;
	if (scanf("%d", &T) != 1) return 0;
	while (T--) {
		int N;
		if (scanf("%d", &N) != 1) return 0;
		long long a[105];
		for (int i = 0; i < N; ++i) scanf("%lld", &a[i]);

		long long best = a[0] - 0; // min over (Ai - i) for i < j, using 0-based i
		long long ans = best + (a[1] + 1); // initialize with j=1 (second element)
		for (int j = 1; j < N; ++j) {
			long long cand = best + (a[j] + j);
			if (cand < ans) ans = cand;
			long long val = a[j] - j;
			if (val < best) best = val;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
