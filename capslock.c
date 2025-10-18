#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    int change_case = 0;

    if (len == 0) {
        // Empty string, do nothing
    } else if (len == 1) {
        // Single letter, always flip case
        change_case = 1;
    } else {
        // Check if all characters from the second one are uppercase
        int rest_are_upper = 1;
        for (int i = 1; i < len; i++) {
            if (islower(s[i])) {
                rest_are_upper = 0;
                break;
            }
        }
        // If they are, the rule applies
        if (rest_are_upper) {
            change_case = 1;
        }
    }

    if (change_case) {
        for (int i = 0; i < len; i++) {
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }

    printf("%s\n", s);

    return 0;
}
