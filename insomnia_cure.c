#include <stdio.h>

int main() {
	int k, l, m, n, d;
	if (scanf("%d %d %d %d %d", &k, &l, &m, &n, &d) != 5) {
		return 0;
	}

	int damaged = 0;
	for (int dragon = 1; dragon <= d; dragon++) {
		if (dragon % k == 0 || dragon % l == 0 || dragon % m == 0 || dragon % n == 0) {
			damaged++;
		}
	}

	printf("%d\n", damaged);
	return 0;
}
