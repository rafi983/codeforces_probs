#include <stdio.h>

int main(void) {
	int t;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		char a[11], b[11], c[11];
		if (scanf("%10s %10s %10s", a, b, c) != 3) return 0;
		putchar(a[0]);
		putchar(b[0]);
		putchar(c[0]);
		putchar('\n');
	}
	return 0;
}
