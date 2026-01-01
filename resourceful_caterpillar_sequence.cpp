#include <iostream>
#include <vector>
#include <numeric>

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

    if (n == 2) {
        cout << 0 << "\n";
        return;
    }

    vector<bool> is_leaf(n + 1, false);
    int leaf_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            is_leaf[i] = true;
            leaf_count++;
        }
    }

    int non_leaf_count = n - leaf_count;
    long long ans = (long long)leaf_count * non_leaf_count;

    vector<int> L(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int neighbor : adj[i]) {
            if (is_leaf[neighbor]) {
                L[i]++;
            }
        }
    }

    vector<bool> in_S(n + 1, false);
    int total_S = 0;
    for (int i = 1; i <= n; ++i) {
        if (!is_leaf[i] && L[i] == 0) {
            in_S[i] = true;
            total_S++;
        }
    }

    vector<int> subtree_S(n + 1, 0);
    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    vector<int> stack;
    stack.push_back(1);
    parent[1] = 0;

    // Iterative DFS to establish parent pointers and processing order
    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (int v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                stack.push_back(v);
            }
        }
    }

    // Reverse order to compute subtree sums (bottom-up)
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        subtree_S[u] = (in_S[u] ? 1 : 0);
        for (int v : adj[u]) {
            if (v != parent[u]) {
                subtree_S[u] += subtree_S[v];
            }
        }
    }

    long long count_B = 0;
    for (int q = 1; q <= n; ++q) {
        if (is_leaf[q]) continue;

        for (int z : adj[q]) {
            if (L[z] >= 1) {
                int s_count = 0;
                if (parent[z] == q) {
                    // z is child of q
                    s_count = subtree_S[z];
                } else {
                    // z is parent of q
                    s_count = total_S - subtree_S[q];
                }
                count_B += s_count;
            }
        }
    }

    cout << ans + count_B << "\n";
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

