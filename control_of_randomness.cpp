#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> parent(n + 1, 0);
    vector<int> depth(n + 1, 0);
    vector<int> order;
    queue<int> Q;

    Q.push(1);
    parent[1] = 0;
    depth[1] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                Q.push(v);
            }
        }
    }

    int max_coins = n;
    vector<vector<long long>> dp(n + 1, vector<long long>(max_coins + 1));

    for (int u : order) {
        if (u == 1) {
            for (int k = 0; k <= max_coins; ++k) dp[u][k] = 0;
            continue;
        }

        int p = parent[u];
        int pp = parent[p]; // 0 if p=1

        if (p == 1) {
            for (int k = 0; k <= max_coins; ++k) {
                if (k >= 1) {
                    dp[u][k] = 1;
                } else {
                    dp[u][k] = 2LL * deg[u] - 1;
                }
            }
        } else {
            for (int k = 0; k <= max_coins; ++k) {
                long long val_nopay = 2LL * deg[u] + dp[pp][k];
                long long val_pay = -1;
                if (k >= 1) {
                    val_pay = 2 + dp[pp][k - 1];
                }

                if (val_pay != -1) {
                    dp[u][k] = min(val_nopay, val_pay);
                } else {
                    dp[u][k] = val_nopay;
                }
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int v, p;
        cin >> v >> p;
        if (p > n) p = n;

        long long ans = 1 + dp[parent[v]][p];
        cout << ans % MOD << (i == q - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

