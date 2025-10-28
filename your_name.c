#include <stdio.h>
#include <string.h>

int main(void) {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int n;
        char s[32], t[32];
        if (scanf("%d", &n) != 1) return 0;
        if (scanf("%31s %31s", s, t) != 2) return 0;

        if ((int)strlen(s) != n || (int)strlen(t) != n) {
            puts("NO");
            continue;
        }

        int cntS[26] = {0}, cntT[26] = {0};
        for (int i = 0; i < n; ++i) {
            cntS[s[i]-'a']++;
            cntT[t[i]-'a']++;
        }
        int ok = 1;
        for (int i = 0; i < 26; ++i) {
            if (cntS[i] != cntT[i]) { ok = 0; break; }
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}

