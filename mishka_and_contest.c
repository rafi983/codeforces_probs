#include <stdio.h>

int main(void) {
	int n = 0;
	int k = 0;
	if (scanf("%d %d", &n, &k) != 2) {
		return 0;
	}

	int problems[100];
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &problems[i]) != 1) {
			problems[i] = 0;
		}
	}

	int left = 0;
	int right = n - 1;
	int solved = 0;

	while (left <= right) {
		int left_ok = problems[left] <= k;
		int right_ok = problems[right] <= k;
		if (!left_ok && !right_ok) {
			break;
		}
		if (left_ok) {
			++left;
			++solved;
		} else if (right_ok) {
			--right;
			++solved;
		}
	}

	printf("%d\n", solved);
	return 0;
}
