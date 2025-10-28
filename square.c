#include <stdio.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int a, b, c, d;
        if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) return 0;
        if (a == b && b == c && c == d) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}

