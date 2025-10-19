#include <stdio.h>

int main(void) {
	int n = 0;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	int givers[100] = {0};
	for (int receiver = 1; receiver <= n; ++receiver) {
		int giver = 0;
		if (scanf("%d", &giver) != 1) {
			giver = 0;
		}
		if (giver >= 1 && giver <= n) {
			givers[giver - 1] = receiver;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (i) {
			printf(" ");
		}
		printf("%d", givers[i]);
	}
	printf("\n");
	return 0;
}
