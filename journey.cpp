#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

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

struct Edge {
    int u, v, w, id;
};

struct Node {
    vector<int> children;
    long long val;
    int id;
};

int n, m;
vector<Edge> edges;
vector<int> deg;
vector<Node> tree_nodes;
vector<int> dsu_node_idx; // Maps DSU root to tree node index

void solve() {
    if (!(cin >> n >> m)) return;
    deg.assign(n + 1, 0);
    edges.clear();
    long long base_cost = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i + 1});
        deg[u]++;
        deg[v]++;
        base_cost += w;
    }

    if (n == 1) {
        cout << base_cost << "\n";
        return;
    }

    tree_nodes.clear();
    tree_nodes.resize(n + 1);
    for(int i=1; i<=n; ++i) {
        tree_nodes[i].id = i;
        tree_nodes[i].val = INF;
    }

    dsu_node_idx.resize(n + 1);
    iota(dsu_node_idx.begin(), dsu_node_idx.end(), 0); // 1-based mapping

    DSU dsu(n);
    int next_node_id = n + 1;

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        int root_u = dsu.find(u);
        int root_v = dsu.find(v);

        if (root_u != root_v) {
            // Merge
            int node_u = dsu_node_idx[root_u];
            int node_v = dsu_node_idx[root_v];

            Node new_node;
            new_node.id = next_node_id;
            new_node.val = w;
            new_node.children.push_back(node_u);
            new_node.children.push_back(node_v);

            tree_nodes.push_back(new_node);

            dsu.unite(u, v);
            int new_root = dsu.find(u);
            dsu_node_idx[new_root] = next_node_id; // Update mapping
            next_node_id++;
        } else {
            // Same component
            int node_root = dsu_node_idx[root_u];

            if (node_root < tree_nodes.size()) {
                 tree_nodes[node_root].val = min(tree_nodes[node_root].val, (long long)w);
            }
        }
    }

    for (int i = tree_nodes.size() - 1; i >= 1; --i) {
        for (int child : tree_nodes[i].children) {
            tree_nodes[child].val = min(tree_nodes[child].val, tree_nodes[i].val);
        }
    }

    long long matching_cost = 0;
    vector<int> unmatched(tree_nodes.size(), 0);

    for (int i = 1; i < tree_nodes.size(); ++i) {
        if (i <= n) {
            // Leaf
            if (deg[i] % 2 != 0) {
                unmatched[i] = 1;
            }
        } else {
            // Internal node
            int count = 0;
            for (int child : tree_nodes[i].children) {
                count += unmatched[child];
            }

            long long pairs = count / 2;
            matching_cost += pairs * tree_nodes[i].val;
            unmatched[i] = count % 2;
        }
    }

    cout << base_cost + matching_cost << "\n";
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

