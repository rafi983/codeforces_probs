#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 8005;

typedef long long ll;

static ll a[MAXN];
static ll c[MAXN];
static ll dp[MAXN];

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

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
        cout << ans << endl;
    }

    return 0;
}

