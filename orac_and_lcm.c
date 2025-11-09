#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXA 200000

static int spf[MAXA + 1];
static int cnt_[MAXA + 1];
static int min1_[MAXA + 1];
static int min2_[MAXA + 1];

static void build_spf(void) {
    for (int i = 0; i <= MAXA; ++i) spf[i] = 0;
    for (int i = 2; i <= MAXA; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            if ((long long)i * i <= MAXA) {
                for (long long j = 1LL * i * i; j <= MAXA; j += i) {
                    if (spf[(int)j] == 0) spf[(int)j] = i;
                }
            }
        }
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    build_spf();

    for (int i = 0; i <= MAXA; ++i) {
        cnt_[i] = 0;
        min1_[i] = INT_MAX;
        min2_[i] = INT_MAX;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) x = 0;
        while (x > 1) {
            int p = spf[x];
            if (p == 0) p = x;
            int e = 0;
            while (x % p == 0) {
                x /= p;
                ++e;
            }
            cnt_[p]++;
            if (e < min1_[p]) {
                min2_[p] = min1_[p];
                min1_[p] = e;
            } else if (e < min2_[p]) {
                min2_[p] = e;
            }
        }
    }

    unsigned long long ans = 1ULL;

    for (int p = 2; p <= MAXA; ++p) {
        if (cnt_[p] < n - 1) continue;
        int exp = (cnt_[p] == n) ? min2_[p] : min1_[p];
        if (exp == INT_MAX) continue;
        for (int k = 0; k < exp; ++k) ans *= (unsigned long long)p;
    }

    printf("%llu\n", ans);
    return 0;
}

