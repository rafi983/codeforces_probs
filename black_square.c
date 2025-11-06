#include <stdio.h>
#include <string.h>

int main(void) {
    long long a[4];
    if (scanf("%lld %lld %lld %lld", &a[0], &a[1], &a[2], &a[3]) != 4) return 0;
    static char s[200005];
    if (scanf("%200000s", s) != 1) return 0;

    long long total = 0;
    for (size_t i = 0; s[i]; ++i) {
        char c = s[i];
        if (c >= '1' && c <= '4') {
            total += a[c - '1'];
        }
    }

    printf("%lld\n", total);
    return 0;
}

