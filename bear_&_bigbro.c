#include <stdio.h>

int main(void) {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2) {
        return 0;
    }

    int years = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        ++years;
    }

    printf("%d\n", years);

    return 0;
}
