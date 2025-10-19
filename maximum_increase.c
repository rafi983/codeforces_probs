#include <stdio.h>

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	long long prev = 0, cur = 0;
	int best = 0, len = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &cur);
		if (i == 0 || cur <= prev) {
			len = 1;
		} else {
			++len;
		}
		if (len > best) best = len;
		prev = cur;
	}
	printf("%d\n", best);
	return 0;
}
