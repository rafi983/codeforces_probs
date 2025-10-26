#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[4];
        scanf("%s", s);

        if ((toupper(s[0]) == 'Y') &&
            (toupper(s[1]) == 'E') &&
            (toupper(s[2]) == 'S')) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

