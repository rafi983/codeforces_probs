#include <stdio.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		int n;
		scanf("%d", &n);
		int seen[55] = {0};
		int first = 1;
		for (int i = 0; i < 2 * n; ++i) {
			int x; scanf("%d", &x);
			if (!seen[x]) {
				if (!first) putchar(' ');
				first = 0;
				printf("%d", x);
				seen[x] = 1;
			}
		}
		putchar('\n');
	}
	return 0;
}
