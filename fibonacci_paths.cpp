#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 998244353;

struct Edge {
    int u, v;
    long long sum_val;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.sum_val > b.sum_val;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<Edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, a[u] + a[v]});
    }

    sort(edges.begin(), edges.end(), compareEdges);

    vector<map<long long, int>> next_paths(n + 1);

    long long total_ans = 0;

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        long long required_val = edge.sum_val;

        int ways = 1;
        auto it = next_paths[v].find(required_val);
        if (it != next_paths[v].end()) {
            ways = (ways + it->second) % MOD;
        }

        next_paths[u][a[v]] = (next_paths[u][a[v]] + ways) % MOD;

        total_ans = (total_ans + ways) % MOD;
    }

    cout << total_ans << "\n";
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

