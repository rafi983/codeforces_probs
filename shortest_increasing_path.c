#include <stdio.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		long long x, y;
		if (scanf("%lld %lld", &x, &y) != 2) return 0;

		if (y >= x + 1) {
			printf("2\n");
		} else if (x >= y + 2 && y >= 2) {
			printf("3\n");
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
