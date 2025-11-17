#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, sz;

    explicit DSU(int n) : n(n), p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return false;
        }

        if (sz[a] < sz[b]) {
            swap(a, b);
        }

        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) {
        return 0;
    }

    while (T--) {
        int n;
        cin >> n;

        struct Edge {
            int a, b, idx;
        };

        vector<Edge> edges(n);

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            edges[i] = {a, b, i + 1};
        }

        DSU dsu(2 * n + 5);
        vector<int> chosen;
        chosen.reserve(n);

        for (auto &e : edges) {
            if (dsu.unite(e.a, e.b)) {
                chosen.push_back(e.idx);
            }
        }

        cout << chosen.size() << '\n';

        if (!chosen.empty()) {
            for (size_t i = 0; i < chosen.size(); ++i) {
                cout << chosen[i] << (i + 1 == chosen.size() ? '\n' : ' ');
            }
        } else {
            cout << '\n';
        }
    }

    return 0;
}

