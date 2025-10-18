#include <stdio.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    while (t--) {
        long long n;
        if (scanf("%lld", &n) != 1) {
            return 0;
        }

        if (n % 2 == 0) {
            printf("%lld\n", n / 2 - 1);
        } else {
            printf("%lld\n", n / 2);
        }
    }

    return 0;
}
