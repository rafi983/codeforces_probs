#include <stdio.h>

int main(void) {
	int n = 0;
	if (scanf("%d", &n) != 1) {
		return 0;
	}

	int free_officers = 0;
	int untreated = 0;

	for (int i = 0; i < n; ++i) {
		int event = 0;
		if (scanf("%d", &event) != 1) {
			event = 0;
		}
		if (event == -1) {
			if (free_officers > 0) {
				--free_officers;
			} else {
				++untreated;
			}
		} else {
			free_officers += event;
		}
	}

	printf("%d\n", untreated);
	return 0;
}
