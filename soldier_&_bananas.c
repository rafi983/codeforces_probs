#include <stdio.h>

int main(void) {
    long long k, n, w;
    if (scanf("%lld %lld %lld", &k, &n, &w) != 3) {
        return 0;
    }
    long long total_cost = k * w * (w + 1) / 2; // arithmetic series sum
    long long borrow = total_cost - n;
    if (borrow < 0) {
        borrow = 0;
    }
    printf("%lld\n", borrow);
    return 0;
}
