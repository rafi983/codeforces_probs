#include <stdio.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    while (t--) {
        int n;
        char s[55];
        scanf("%d", &n);
        scanf("%s", s);
        int l = -1;
        int r = -1;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] != s[i + 1]) {
                l = i + 1;
                r = i + 2;
                break;
            }
        }
        if (l == -1) {
            printf("-1 -1\n");
        } else {
            printf("%d %d\n", l, r);
        }
    }
    return 0;
}