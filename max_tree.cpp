#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long x, y;
        cin >> u >> v >> x >> y;

        if (x > y) {

            adj[u].push_back(v);
            deg[v]++;
        } else if (x < y) {
            // We want p[u] < p[v] => p[v] > p[u].
            // v comes before u.
            adj[v].push_back(u);
            deg[u]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> p(n + 1);
    int current_val = n;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        p[u] = current_val--;

        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
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

