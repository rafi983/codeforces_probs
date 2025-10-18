#include <stdio.h>
#include <string.h>

int main() {
	char guest[101];
	char host[101];
	char pile[201];

	if (scanf("%100s", guest) != 1) {
		return 0;
	}
	if (scanf("%100s", host) != 1) {
		return 0;
	}
	if (scanf("%200s", pile) != 1) {
		return 0;
	}

	int letters[26] = {0};

	for (int i = 0; guest[i] != '\0'; i++) {
		letters[guest[i] - 'A']++;
	}
	for (int i = 0; host[i] != '\0'; i++) {
		letters[host[i] - 'A']++;
	}

	for (int i = 0; pile[i] != '\0'; i++) {
		letters[pile[i] - 'A']--;
	}

	for (int i = 0; i < 26; i++) {
		if (letters[i] != 0) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}
