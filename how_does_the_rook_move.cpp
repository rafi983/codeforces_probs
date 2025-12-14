#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 300005;

long long dp[MAXN];

void precompute() {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        dp[i] = (dp[i - 1] + 2LL * (i - 1) * dp[i - 2]) % MOD;
    }
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    int used = 0;
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        if (r == c) {
            used += 1;
        } else {
            used += 2;
        }
    }

    int remaining = n - used;
    if (remaining < 0) remaining = 0;

    cout << dp[remaining] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

