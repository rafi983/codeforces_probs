#include <stdio.h>

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	unsigned int a[100005];
	for (int i = 0; i < n; ++i) scanf("%u", &a[i]);
	int l = 0, r = n - 1;
	int ok = 1;
	while (l < r) {
		if (a[l] != a[r]) { ok = 0; break; }
		++l; --r;
	}
	puts(ok ? "YES" : "NO");
	return 0;
}
