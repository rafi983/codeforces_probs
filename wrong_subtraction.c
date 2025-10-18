#include <stdio.h>

int main(void) {
    long long n;
    int k;
    if (scanf("%lld %d", &n, &k) != 2) {
        return 0;
    }

    for (int i = 0; i < k; ++i) {
        if (n % 10 != 0) {
            --n;
        } else {
            n /= 10;
        }
    }

    printf("%lld\n", n);

    return 0;
}
