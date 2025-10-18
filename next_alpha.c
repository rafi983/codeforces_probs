#include <stdio.h>

int main() {
	char c;
	scanf("%c", &c);
	if (c == 'z') {
		printf("a\n");
	} else if (c >= 'a' && c < 'z') {
		printf("%c\n", c + 1);
	} else {
		// Invalid input handling (optional)
		printf("Invalid input\n");
	}
	return 0;
}
