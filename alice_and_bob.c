#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    while (t--) {
        int n;
        long long a;
        scanf("%d %lld", &n, &a);

        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            scanf("%lld", &x);

            if (x < a) {
                left++;
            } else if (x > a) {
                right++;
            }
        }

        long long b;
        if (right > left) {
            b = a + 1;
        } else {
            b = a - 1;
        }

        if (b < 0) {
            b = 0;
        }
        if (b > 2000000000LL) {
            b = 2000000000LL;
        }

        printf("%lld\n", b);
    }

    return 0;
}
