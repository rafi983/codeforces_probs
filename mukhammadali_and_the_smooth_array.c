#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAXN 8005

typedef long long ll;

static ll a[MAXN];
static ll c[MAXN];
static ll dp[MAXN];

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        for (int i = 0; i < n; ++i) scanf("%" SCNd64, &a[i]);
        for (int i = 0; i < n; ++i) scanf("%" SCNd64, &c[i]);

        ll total = 0;
        for (int i = 0; i < n; ++i) total += c[i];

        ll best = 0;
        for (int i = 0; i < n; ++i) {
            ll bestPrev = 0;
            for (int j = 0; j < i; ++j) {
                if (a[j] <= a[i] && dp[j] > bestPrev) bestPrev = dp[j];
            }
            dp[i] = bestPrev + c[i];
            if (dp[i] > best) best = dp[i];
        }

        ll ans = total - best;
        printf("%" PRId64 "\n", ans);
    }
    return 0;
}