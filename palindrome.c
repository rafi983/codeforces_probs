#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1005]; // 1000 + padding for null and newline
    if (!fgets(s, sizeof(s), stdin)) return 1;
    
    // Remove trailing newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[--len] = '\0';
    
    // Compare characters from both ends
    int is_palindrome = 1;
    for (size_t i = 0; i < len/2; i++) {
        if (s[i] != s[len-1-i]) {
            is_palindrome = 0;
            break;
        }
    }
    
    puts(is_palindrome ? "YES" : "NO");
    return 0;
}
