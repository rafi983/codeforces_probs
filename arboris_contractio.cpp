#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
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

    vector<bool> is_leaf(n + 1, false);
    int total_leaves = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            is_leaf[i] = true;
            total_leaves++;
        }
    }

    int max_score = 0;
    for (int i = 1; i <= n; ++i) {
        int current_score = 0;
        if (is_leaf[i]) {
            current_score += 1;
        }
        for (int neighbor : adj[i]) {
            if (is_leaf[neighbor]) {
                current_score += 1;
            }
        }
        max_score = max(max_score, current_score);
    }

    cout << total_leaves - max_score << endl;
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

