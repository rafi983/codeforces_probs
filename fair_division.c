#include <stdio.h>

int main(void) {
	int t = 0;
	if (scanf("%d", &t) != 1) {
		return 0;
	}

	while (t--) {
		int n = 0;
		if (scanf("%d", &n) != 1) {
			n = 0;
		}

		int ones = 0;
		int twos = 0;
		for (int i = 0; i < n; ++i) {
			int weight = 0;
			if (scanf("%d", &weight) != 1) {
				weight = 0;
			}
			if (weight == 1) {
				++ones;
			} else if (weight == 2) {
				++twos;
			}
		}

		int total_weight = ones + 2 * twos;
		if (total_weight % 2 != 0) {
			printf("NO\n");
			continue;
		}

		int half = total_weight / 2;
		int can_use_twos = twos < (half / 2) ? twos : (half / 2);
		int weight_from_twos = can_use_twos * 2;
		int remaining = half - weight_from_twos;
		if (remaining <= ones) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
