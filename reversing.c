#include <stdio.h>

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	unsigned int a[1005];
	for (int i = 0; i < n; ++i) scanf("%u", &a[i]);
	for (int i = n - 1; i >= 0; --i) {
		printf("%u", a[i]);
		if (i) putchar(' ');
	}
	putchar('\n');
	return 0;
}
