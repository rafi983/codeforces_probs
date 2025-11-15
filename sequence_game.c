#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n;
        scanf("%d", &n);
        long long mn = 0, mx = 0, val;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &val);
            if (i == 0) {
                mn = mx = val;
            } else {
                if (val < mn) mn = val;
                if (val > mx) mx = val;
            }
        }
        long long x;
        scanf("%lld", &x);
        if (mn <= x && x <= mx) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}