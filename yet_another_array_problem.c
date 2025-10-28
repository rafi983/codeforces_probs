#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

static unsigned long long gcd_ull(unsigned long long a, unsigned long long b) {
    while (b) {
        unsigned long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static int is_prime_ull(unsigned long long x) {
    if (x < 2) return 0;
    if (x % 2ULL == 0ULL) return x == 2ULL;
    for (unsigned long long d = 3ULL; d * d <= x; d += 2ULL) {
        if (x % d == 0ULL) return 0;
    }
    return 1;
}

static unsigned long long next_prime_after(unsigned long long p) {
    if (p < 2ULL) return 2ULL;
    unsigned long long x = p + 1ULL;
    if (x % 2ULL == 0ULL) x++;
    while (!is_prime_ull(x)) x += 2ULL;
    return x;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        unsigned long long g = 0ULL;
        for (int i = 0; i < n; ++i) {
            unsigned long long a;
            if (scanf("%" SCNu64, &a) != 1) return 0;
            if (g == 0ULL) g = a; else g = gcd_ull(g, a);
        }
        unsigned long long p = 2ULL;
        while (g % p == 0ULL) {
            p = next_prime_after(p);
        }
        printf("%" PRIu64 "\n", p);
    }
    return 0;
}

