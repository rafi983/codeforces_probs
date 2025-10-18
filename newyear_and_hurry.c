#include <stdio.h>

int main() {
	int n, k;
	if (scanf("%d %d", &n, &k) != 2) {
		return 0;
	}

	int remaining = 240 - k;
	if (remaining <= 0) {
		printf("0\n");
		return 0;
	}

	int solved = 0;
	for (int i = 1; i <= n; i++) {
		int time_needed = 5 * i;
		if (remaining - time_needed >= 0) {
			remaining -= time_needed;
			solved++;
		} else {
			break;
		}
	}

	printf("%d\n", solved);
	return 0;
}
