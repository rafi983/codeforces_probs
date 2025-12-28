#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

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

    int ans = 0;

    // Case 1: Adjacent pairs
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (u < v) {
                ans = max(ans, deg[u] + deg[v] - 2);
            }
        }
    }

    // Case 2: Non-adjacent pairs
    vector<pair<int, int>> sorted_nodes(n);
    for (int i = 1; i <= n; ++i) {
        sorted_nodes[i - 1] = {deg[i], i};
    }
    sort(sorted_nodes.rbegin(), sorted_nodes.rend());

    vector<int> tag(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int u = sorted_nodes[i].second;
        int d_u = sorted_nodes[i].first;

        if (d_u + sorted_nodes[0].first - 1 <= ans) {
            break;
        }

        tag[u] = u;
        for (int v : adj[u]) {
            tag[v] = u;
        }

        for (int j = 0; j < n; ++j) {
            int v = sorted_nodes[j].second;
            int d_v = sorted_nodes[j].first;

            if (tag[v] == u) continue;

            ans = max(ans, d_u + d_v - 1);
            break;
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

