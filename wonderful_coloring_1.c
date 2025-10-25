#include <stdio.h>
#include <string.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		char s[55];
		if (scanf("%54s", s) != 1) return 0;

		int freq[26] = {0};
		for (int i = 0; s[i]; ++i) {
			int idx = s[i] - 'a';
			if (idx >= 0 && idx < 26) freq[idx]++;
		}

		int pairs = 0;   
		int singles = 0;
		for (int i = 0; i < 26; ++i) {
			if (freq[i] >= 2) pairs++;
			else if (freq[i] == 1) singles++;
		}

		int k = pairs + singles / 2;
		printf("%d\n", k);
	}
	return 0;
}
