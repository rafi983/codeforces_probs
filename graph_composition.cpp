#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent;
    int num_components;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        num_components = n;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            num_components--;
        }
    }
};

void solve() {
    int n, m1, m2;
    if (!(cin >> n >> m1 >> m2)) return;

    vector<pair<int, int>> edges_f(m1);
    for (int i = 0; i < m1; ++i) {
        cin >> edges_f[i].first >> edges_f[i].second;
    }

    DSU dsu_g(n);
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        dsu_g.unite(u, v);
    }

    DSU dsu_f(n);
    int ops = 0;

    for (const auto& edge : edges_f) {
        int u = edge.first;
        int v = edge.second;

        if (dsu_g.find(u) != dsu_g.find(v)) {
            // Edge in F connects different components in G -> Remove it
            ops++;
        } else {
            // Edge in F connects same component in G -> Keep it
            dsu_f.unite(u, v);
        }
    }


    ops += (dsu_f.num_components - dsu_g.num_components);

    cout << ops << endl;
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

