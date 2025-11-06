#include <stdio.h>

int main(void) {
    long long M, N;
    if (scanf("%lld %lld", &M, &N) != 2) return 0;
    long long ans = (M * N) / 2;
    printf("%lld\n", ans);
    return 0;
}

