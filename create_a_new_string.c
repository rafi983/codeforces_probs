#include <stdio.h>
#include <string.h>

// Helper to strip trailing \r and \n
static void strip_eol(char *s) {
	size_t n = strlen(s);
	while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
		s[--n] = '\0';
	}
}

int main(void) {
	char S[1105], T[1105]; // allow some headroom
	if (!fgets(S, sizeof(S), stdin)) return 0;
	if (!fgets(T, sizeof(T), stdin)) return 0;
	strip_eol(S);
	strip_eol(T);
	printf("%zu %zu\n", strlen(S), strlen(T));
	printf("%s %s\n", S, T);
	return 0;
}

