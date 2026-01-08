#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

namespace ZamanSolver {
    const int MOD = 998244353;
    const int MAX_M = 3005;
    vector<int> divs[MAX_M];
    bool precomputed = false;

    void precompute() {
        if (precomputed) return;
        for (int i = 1; i < MAX_M; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    divs[i].push_back(j);
                    if (j * j != i) {
                        divs[i].push_back(i / j);
                    }
                }
            }
        }
        precomputed = true;
    }

    void zaman() {
        int n, m;
        if (!(cin >> n >> m)) return;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == -1) exit(0);
        }

        // Validity check
        for (int x : a) {
            if (x < 0 || x > m) {
                cout << 0 << "\n";
                return;
            }
        }

        if (a[0] != 0 && a[0] != 1) {
            cout << 0 << "\n";
            return;
        }

        vector<int> dp(m + 1, 0);

        dp[1] = 1;

        for (int i = 1; i < n; ++i) {
            vector<int> next_dp(m + 1, 0);

            for (int u = 1; u <= m; ++u) {
                if (dp[u] == 0) continue;

                for (int d : divs[u]) {
                    int v = u + d;
                    if (v > m) continue;

                    if (a[i] != 0 && a[i] != v) continue;

                    next_dp[v] = (next_dp[v] + dp[u]) % MOD;
                }
            }
            dp = std::move(next_dp);
        }

        int ans = 0;
        for (int v = 1; v <= m; ++v) {
            ans = (ans + dp[v]) % MOD;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ZamanSolver::precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            ZamanSolver::zaman();
        }
    }
    return 0;
}
