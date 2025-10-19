#include <stdio.h>

int main(void) {
	int n = 0;
	if (scanf("%d", &n) != 1 || n <= 0) {
		return 0;
	}

	int cards[1000];
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &cards[i]) != 1) {
			cards[i] = 0;
		}
	}

	int left = 0;
	int right = n - 1;
	int sereja = 0;
	int dima = 0;
	int turn = 0;

	while (left <= right) {
		int pick_left = cards[left];
		int pick_right = cards[right];
		int chosen = pick_left >= pick_right ? pick_left : pick_right;
		if (chosen == pick_left) {
			++left;
		} else {
			--right;
		}

		if (turn == 0) {
			sereja += chosen;
		} else {
			dima += chosen;
		}
		turn ^= 1;
	}

	printf("%d %d\n", sereja, dima);
	return 0;
}
