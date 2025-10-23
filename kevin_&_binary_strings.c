#include <stdio.h>
#include <string.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		char s[6005];
		if (scanf("%6000s", s) != 1) return 0;
		int n = (int)strlen(s);

		int pos = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') { pos = i; break; }
		}

		if (pos == -1) {
			printf("1 1 1 %d\n", n);
			continue;
		}

		int L = n - pos;           
		int best = 0;               
		int limit = pos;

		for (int j = 0; j <= limit; ++j) {
			int decided = 0;
			for (int q = 0; q < L; ++q) {
				char a = s[j + q];
				char b = s[best + q];
				if (a == b) continue;
				char Bq = s[pos + q];
				if (Bq == '0') {
					decided = (a == '1') ? 1 : -1;
				} else {
					decided = (a == '0') ? 1 : -1;
				}
				break;
			}
			if (decided == 1) best = j;
		}

		int l1 = best + 1;
		int r1 = best + L;
		int l2 = 1;
		int r2 = n;
		printf("%d %d %d %d\n", l1, r1, l2, r2);
	}
	return 0;
}
