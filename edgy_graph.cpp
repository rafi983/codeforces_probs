#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct Edge {
    int u, v, w;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges(m);
    vector<int> min_edge(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        min_edge[edges[i].u] = min(min_edge[edges[i].u], edges[i].w);
        min_edge[edges[i].v] = min(min_edge[edges[i].v], edges[i].w);
    }

    for (const auto& edge : edges) {
        if (min_edge[edge.u] != edge.w && min_edge[edge.v] != edge.w) {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << min_edge[i] << (i == n ? "" : " ");
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

