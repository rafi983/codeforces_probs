#include <stdio.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    while (t--) {
        char s[300005];
        if (scanf("%300000s", s) != 1) {
            return 0;
        }

        int n = (int)strlen(s);
        int infinite = 0;

        for (int i = 0; i + 1 < n; i++) {
            if ((s[i] == '>' || s[i] == '*') && (s[i + 1] == '<' || s[i + 1] == '*')) {
                infinite = 1;
                break;
            }
        }

        if (infinite) {
            printf("-1\n");
            continue;
        }

        int L = 0;
        while (L < n && s[L] == '<') {
            L++;
        }

        int R = 0;
        while (R < n && s[n - 1 - R] == '>') {
            R++;
        }

        int hasStar = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                hasStar = 1;
                break;
            }
        }

        int ans = hasStar ? (L > R ? L : R) + 1 : (L > R ? L : R);
        printf("%d\n", ans);
    }

    return 0;
}
