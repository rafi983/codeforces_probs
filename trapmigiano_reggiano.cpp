#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma comment(linker, "/STACK:268435456")

const int MAXN = 100005;
vector<int> adj[MAXN];
int special_child[MAXN];
vector<int> result_perm;
int st_node, en_node;

bool dfs_path(int u, int p) {
    if (u == st_node) {
        return true;
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        if (dfs_path(v, u)) {
            special_child[u] = v;
            return true;
        }
    }
    return false;
}

void dfs_order(int u, int p) {
    for (int v : adj[u]) {
        if (v == p || v == special_child[u]) continue;
        dfs_order(v, u);
    }
    if (special_child[u] != 0) {
        dfs_order(special_child[u], u);
    }
    result_perm.push_back(u);
}

void solve() {
    int n;
    if (!(cin >> n >> st_node >> en_node)) return;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        special_child[i] = 0;
    }
    result_perm.clear();

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_path(en_node, -1);
    dfs_order(en_node, -1);

    for (int i = 0; i < n; ++i) {
        cout << result_perm[i] << (i == n - 1 ? "" : " ");
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
