#include <stdio.h>
#include <string.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        char s[205];
        if (scanf("%s", s) != 1) return 0;
        for (int i = 0; i < n && s[i]; ++i) {
            char c = s[i];
            if (c == 'U') s[i] = 'D';
            else if (c == 'D') s[i] = 'U';
            else if (c == 'L' || c == 'R') {
            } else {
            }
        }
        s[n] = '\0';
        printf("%s\n", s);
    }
    return 0;
}

