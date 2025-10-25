#include <stdio.h>
#include <string.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		int n;
		if (scanf("%d", &n) != 1) return 0;
		char s[200005 + 5];
		if (scanf("%200010s", s) != 1) return 0;

		int freq[26] = {0};
		for (int i = 0; s[i]; ++i) freq[s[i]-'a']++;

		int ok = 0;
		if (n >= 3) {
			for (int i = 1; i <= n-2; ++i) {
				if (freq[s[i]-'a'] >= 2) { ok = 1; break; }
			}
		}
		printf(ok ? "Yes\n" : "No\n");
	}
	return 0;
}

