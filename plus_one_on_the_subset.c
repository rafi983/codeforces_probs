#include <stdio.h>
#include <limits.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        long long mn = LLONG_MAX, mx = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            long long x;
            scanf("%lld", &x);
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }
        printf("%lld\n", mx - mn);
    }
    return 0;
}