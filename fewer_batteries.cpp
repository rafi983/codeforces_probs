#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    long long w;
};

int n, m;
vector<long long> b;
vector<vector<Edge>> adj;

bool check(long long x) {
    vector<long long> dp(n + 1, -1);
    dp[1] = 0;

    for (int u = 1; u <= n; ++u) {
        if (dp[u] == -1) continue;

        long long current_limit = dp[u] + b[u];
        if (current_limit > x) current_limit = x;

        for (const auto& edge : adj[u]) {
            if (current_limit >= edge.w) {
                if (current_limit > dp[edge.to]) {
                    dp[edge.to] = current_limit;
                }
            }
        }
    }
    return dp[n] != -1;
}

void solve() {
    if (!(cin >> n >> m)) return;

    b.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    adj.assign(n + 1, vector<Edge>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    long long low = 0, high = 2e14 + 7; // Sufficiently large upper bound
    long long ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
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

