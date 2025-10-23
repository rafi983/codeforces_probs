#include <stdio.h>
#include <string.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		int n;
		if (scanf("%d", &n) != 1) return 0;

		long long ans = 0;
		long long cntFirst[11] = {0};
		long long cntSecond[11] = {0};
		long long cntPair[11][11];
		memset(cntPair, 0, sizeof(cntPair));

		for (int i = 0; i < n; ++i) {
			char s[4];
			if (scanf("%2s", s) != 1) return 0;
			int a = s[0] - 'a';
			int b = s[1] - 'a';

			// Count pairs with same first but different second, and same second but different first
			ans += cntFirst[a] - cntPair[a][b];
			ans += cntSecond[b] - cntPair[a][b];

			// Update counts
			cntFirst[a]++;
			cntSecond[b]++;
			cntPair[a][b]++;
		}

		printf("%lld\n", ans);
	}
	return 0;
}

