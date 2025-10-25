#include <stdio.h>
#include <string.h>

int main(void) {
	char s[100005];
	if (scanf("%100000s", s) != 1) return 0;

	char mx = 'a';
	for (int i = 0; s[i]; ++i) {
		if (s[i] > mx) mx = s[i];
	}

	for (int i = 0; s[i]; ++i) {
		if (s[i] == mx) putchar(mx);
	}
	putchar('\n');
	return 0;
}

