#include <stdio.h>

int main() {
	int n, m;
	if (scanf("%d %d", &n, &m) != 2) {
		return 0;
	}

	for (int row = 1; row <= n; row++) {
		if (row % 2 == 1) {
			for (int col = 0; col < m; col++) {
				putchar('#');
			}
		} else {
			int place_right = (row / 2) % 2 == 1;
			for (int col = 0; col < m; col++) {
				if ((place_right && col == m - 1) || (!place_right && col == 0)) {
					putchar('#');
				} else {
					putchar('.');
				}
			}
		}
		putchar('\n');
	}

	return 0;
}
