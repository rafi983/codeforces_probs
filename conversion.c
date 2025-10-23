#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char s[100005]; // 1e5 + some padding
    if (!fgets(s, sizeof(s), stdin)) return 1;
    
    // Remove trailing newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[--len] = '\0';
    
    // Process each character
    for (size_t i = 0; i < len; i++) {
        if (s[i] == ',') {
            putchar(' ');
        } else if (isupper(s[i])) {
            putchar(tolower(s[i]));
        } else if (islower(s[i])) {
            putchar(toupper(s[i]));
        } else {
            putchar(s[i]);
        }
    }
    putchar('\n');
    return 0;
}
