#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


long long dfs(int u, int p, const vector<vector<int>>& adj, const vector<int>& weights, long long& ans) {
    long long current_weight = weights[u];

    long long max1 = 0;
    long long max2 = 0;

    for (int v : adj[u]) {
        if (v == p) continue;

        long long child_max_down = dfs(v, u, adj, weights, ans);

        long long contribution = max(0LL, child_max_down);

        if (contribution > max1) {
            max2 = max1;
            max1 = contribution;
        } else if (contribution > max2) {
            max2 = contribution;
        }
    }

    ans = max(ans, current_weight + max1 + max2);

    return current_weight + max1;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    vector<int> weights(n + 1);
    for (int i = 1; i <= n; ++i) {
        weights[i] = degree[i] - 2;
    }

    long long ans = LLONG_MIN;
    dfs(1, -1, adj, weights, ans);

    cout << ans + 2 << "\n";
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

