#include <stdio.h>

int main(void) {
	char program[128];
	if (!fgets(program, sizeof program, stdin)) {
		return 0;
	}

	for (int i = 0; program[i] != '\0'; ++i) {
		if (program[i] == 'H' || program[i] == 'Q' || program[i] == '9') {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}
