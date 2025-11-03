#include <stdio.h>
#include <string.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        char s[205];
        if (scanf("%d", &n) != 1) return 0;
        if (scanf("%204s", s) != 1) return 0;

        long long sum = 0;
        int extra = 0;
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            sum += d;
            if (i < n - 1 && d != 0) extra++;
        }
        long long ans = sum + extra;
        printf("%lld\n", ans);
    }
    return 0;
}

