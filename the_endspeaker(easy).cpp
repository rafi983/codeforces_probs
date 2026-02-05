#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i+1] = P[i] + a[i];
    }

    vector<long long> dp(n + 1, INF);
    dp[n] = 0;

    // Iterate k from m down to 1
    for (int k = m; k >= 1; --k) {
        // Cost for Type 2 operation with current k
        long long cost_op = m - k;
        long long capacity = b[k-1];

        // Iterate i from n-1 down to 0
        for (int i = n - 1; i >= 0; --i) {

            long long target = capacity + P[i];

            auto it = upper_bound(P.begin(), P.end(), target);
            int next_pos = distance(P.begin(), it) - 1;

            if (next_pos > i) {
                if (dp[next_pos] != INF) {
                    dp[i] = min(dp[i], cost_op + dp[next_pos]);
                }
            }
        }
    }

    if (dp[0] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[0] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
