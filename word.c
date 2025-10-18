#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[101];
    scanf("%s", s);
    
    int uppercase_count = 0, lowercase_count = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            uppercase_count++;
        } else {
            lowercase_count++;
        }
    }
    
    if (uppercase_count > lowercase_count) {
        for (int i = 0; s[i] != '\0'; i++) {
            s[i] = toupper(s[i]);
        }
    } else {
        for (int i = 0; s[i] != '\0'; i++) {
            s[i] = tolower(s[i]);
        }
    }
    
    printf("%s\n", s);
    
    return 0;
}
