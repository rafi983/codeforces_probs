#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353
#define MAXN 200000

static long long fact[MAXN + 5];
static int A[MAXN + 5];

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) fact[i] = (fact[i - 1] * i) % MOD;

    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        scanf("%d", &n);
        int mx = 0, cntmx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            if (A[i] > mx) {
                mx = A[i];
                cntmx = 1;
            } else if (A[i] == mx) {
                cntmx++;
            }
        }
        if (cntmx >= 2) {
            printf("%lld\n", fact[n]);
            continue;
        }
        int smax = 0, cnts = 0;
        for (int i = 0; i < n; ++i) if (A[i] != mx && A[i] > smax) smax = A[i];
        if (mx - smax > 1) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < n; ++i) if (A[i] == smax) cnts++;
        long long ans = fact[n];
        ans = ans * cnts % MOD;
        ans = ans * modpow(cnts + 1, MOD - 2) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}