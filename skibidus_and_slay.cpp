#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string result(n, '0'); // result[i] corresponds to value i+1

    // Check distance 1 (adjacent vertices)
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (u < v) { // Check each edge once
                if (a[u] == a[v]) {
                    result[a[u] - 1] = '1';
                }
            }
        }
    }

    // Check distance 2 (neighbors of the same vertex)
    for (int u = 1; u <= n; ++u) {
        if (adj[u].size() < 2) continue;

        vector<int> neighbor_vals;
        neighbor_vals.reserve(adj[u].size());
        for (int v : adj[u]) {
            neighbor_vals.push_back(a[v]);
        }
        sort(neighbor_vals.begin(), neighbor_vals.end());

        for (size_t i = 0; i < neighbor_vals.size() - 1; ++i) {
            if (neighbor_vals[i] == neighbor_vals[i+1]) {
                result[neighbor_vals[i] - 1] = '1';
            }
        }
    }

    cout << result << endl;
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

