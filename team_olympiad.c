#include <stdio.h>

int main() {
	int n;
	if (scanf("%d", &n) != 1) {
		return 0;
	}

	int prog[5000], math[5000], pe[5000];
	int count_prog = 0, count_math = 0, count_pe = 0;

	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			prog[count_prog++] = i;
		} else if (t == 2) {
			math[count_math++] = i;
		} else if (t == 3) {
			pe[count_pe++] = i;
		}
	}

	int teams = count_prog;
	if (count_math < teams) {
		teams = count_math;
	}
	if (count_pe < teams) {
		teams = count_pe;
	}

	printf("%d\n", teams);
	for (int i = 0; i < teams; i++) {
		printf("%d %d %d\n", prog[i], math[i], pe[i]);
	}

	return 0;
}
