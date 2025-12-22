#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

    int v_deg2 = -1;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 2) {
            v_deg2 = i;
            break;
        }
    }

    if (v_deg2 == -1) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
    int u = adj[v_deg2][0];
    int w = adj[v_deg2][1];

    // Direct u -> v_deg2 -> w
    cout << u << " " << v_deg2 << "\n";
    cout << v_deg2 << " " << w << "\n";

    // DFS for T_u (source component)
    auto dfs_source = [&](auto&& self, int curr, int p, int parity) -> void {
        for (int neighbor : adj[curr]) {
            if (neighbor == p) continue;
            if (parity == 0) {
                cout << curr << " " << neighbor << "\n";
            } else {
                cout << neighbor << " " << curr << "\n";
            }
            self(self, neighbor, curr, 1 - parity);
        }
    };

    // DFS for T_w (sink component)
    auto dfs_sink = [&](auto&& self, int curr, int p, int parity) -> void {
        for (int neighbor : adj[curr]) {
            if (neighbor == p) continue;
            if (parity == 0) {
                cout << neighbor << " " << curr << "\n";
            } else {
                cout << curr << " " << neighbor << "\n";
            }
            self(self, neighbor, curr, 1 - parity);
        }
    };

    dfs_source(dfs_source, u, v_deg2, 0);
    dfs_sink(dfs_sink, w, v_deg2, 0);
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

