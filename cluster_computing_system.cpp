#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    int w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
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
        }
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<Edge> edges;
    // Reserve memory to avoid reallocations.
    // Max edges approx N * log(max_P) * 2 + N
    edges.reserve(n * 32);

    // Forward pass (i from n-1 down to 0)
    // next_list stores (gcd_val, index) for suffixes starting at i+1
    vector<pair<int, int>> next_list;
    for (int i = n - 1; i >= 0; --i) {
        vector<pair<int, int>> curr_list;
        curr_list.reserve(next_list.size() + 1);
        curr_list.push_back({p[i], i});

        for (auto& entry : next_list) {
            int g = std::gcd(p[i], entry.first);
            if (g != curr_list.back().first) {
                curr_list.push_back({g, entry.second});
            }
        }

        // Add edges from current node i to the start of each GCD interval
        for (size_t k = 1; k < curr_list.size(); ++k) {
            edges.push_back({i, curr_list[k].second, curr_list[k].first});
        }

        next_list = std::move(curr_list);
    }

    // Backward pass (i from 0 to n-1)
    next_list.clear();
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> curr_list;
        curr_list.reserve(next_list.size() + 1);
        curr_list.push_back({p[i], i});

        for (auto& entry : next_list) {
            int g = std::gcd(p[i], entry.first);
            if (g != curr_list.back().first) {
                curr_list.push_back({g, entry.second});
            }
        }

        for (size_t k = 1; k < curr_list.size(); ++k) {
            edges.push_back({curr_list[k].second, i, curr_list[k].first});
        }

        next_list = std::move(curr_list);
    }

    // Add adjacent edges to ensure connectivity and cover base cases
    for(int i=0; i<n-1; ++i) {
        edges.push_back({i, i+1, std::gcd(p[i], p[i+1])});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_cost = 0;
    int edges_count = 0;

    for (const auto& e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            total_cost += e.w;
            edges_count++;
        }
    }

    cout << total_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

