#include <stdio.h>
#include <string.h>

int main(void) {
    int t; if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n; scanf("%d", &n);
        int a[105];
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

        char s[205];
        int L = 51;
        for (int i = 0; i < L; ++i) s[i] = 'a';
        s[L] = '\0';

        puts(s);
        for (int i = 0; i < n; ++i) {
            
            if (a[i] < L) {
                s[a[i]] = (s[a[i]] == 'a') ? 'b' : 'a';
            } else {
                while (L <= a[i]) {
                    s[L++] = 'a';
                }
                s[L] = '\0';
            }
            puts(s);
        }
    }
    return 0;
}
