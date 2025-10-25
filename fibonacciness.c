#include <stdio.h>

static int count_fibonacciness(int a1, int a2, int a3, int a4, int a5) {
	int cnt = 0;
	if (a3 == a1 + a2) cnt++;
	if (a4 == a2 + a3) cnt++;
	if (a5 == a3 + a4) cnt++;
	return cnt;
}

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		int a1, a2, a4, a5;
		if (scanf("%d %d %d %d", &a1, &a2, &a4, &a5) != 4) return 0;

		int candidates[3];
		candidates[0] = a1 + a2;   
		candidates[1] = a4 - a2;
		candidates[2] = a5 - a4;   

		int best = 0;
		for (int i = 0; i < 3; ++i) {
			int a3 = candidates[i];
			int c = count_fibonacciness(a1, a2, a3, a4, a5);
			if (c > best) best = c;
		}

		printf("%d\n", best);
	}
	return 0;
}

