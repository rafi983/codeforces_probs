#include <iostream>
#include <vector>

using namespace std;

long long MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

vector<vector<int>> adj;
vector<int> comp;
vector<int> comp_nodes;
vector<long long> s;
int n_vertex;
vector<long long> ans;

void dfs_comp(int u, int c, vector<int>& nodes) {
    comp[u] = c;
    nodes.push_back(u);
    for (int v : adj[u]) {
        if (comp[v] == -1) {
            dfs_comp(v, c, nodes);
        }
    }
}

int dfs_find_path(int u, int target, int p, vector<int>& path) {
    path.push_back(u);
    if (u == target) return 1;
    for (int v : adj[u]) {
        if (v != p) {
            if (dfs_find_path(v, target, u, path)) return 1;
        }
    }
    path.pop_back();
    return 0;
}

int dfs_sz(int u, int p) {
    int sz = 1;
    for (int v : adj[u]) {
        if (v != p) {
            sz += dfs_sz(v, u);
        }
    }
    return sz;
}

void solve() {
    int m;
    if (!(cin >> n_vertex >> m)) return;

    adj.assign(n_vertex + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    comp.assign(n_vertex + 1, -1);
    s.clear();
    vector<vector<int>> all_comp_nodes;
    int k = 0;

    for (int i = 1; i <= n_vertex; ++i) {
        if (comp[i] == -1) {
            vector<int> nodes;
            dfs_comp(i, k, nodes);
            s.push_back(nodes.size());
            all_comp_nodes.push_back(nodes);
            k++;
        }
    }

    long long W;
    if (k == 1) {
        W = 1;
    } else {
        long long prod_s = 1;
        for (long long sz : s) prod_s = (prod_s * sz) % MOD;
        W = (prod_s * power(n_vertex, k - 2)) % MOD;
    }

    ans.assign(n_vertex + 1, 0);

    int c_n = comp[n_vertex];
    int c_m = comp[n_vertex - 1];

    if (c_n == c_m) {
        // Path exists in forest
        vector<int> path;
        dfs_find_path(n_vertex, n_vertex - 1, -1, path);
        // Path is n -> v -> ... -> n-1
        int v = path[1];
        ans[v] = W;
    } else {
        // Different components
        long long s_N = s[c_n];
        long long s_M = s[c_m];

        long long F = (W * modInverse((n_vertex * s_N) % MOD)) % MOD;


        for (int v : adj[n_vertex]) {
            // v is neighbor in C_N
            int sz_subtree = dfs_sz(v, n_vertex);
            // Contribution: F * n * Size
            long long term = (F * n_vertex) % MOD;
            term = (term * sz_subtree) % MOD;
            ans[v] = (ans[v] + term) % MOD;
        }

        // External neighbors
        // For each component c != C_N
        for (int c = 0; c < k; ++c) {
            if (c == c_n) continue;

            long long val = F;
            if (c == c_m) {
                // val = F * (1 + s_N / s_M) = F * (s_M + s_N) / s_M
                long long num = (s_M + s_N) % MOD;
                long long invM = modInverse(s_M);
                val = (((F * num) % MOD) * invM) % MOD;
            }

            for (int node : all_comp_nodes[c]) {
                ans[node] = (ans[node] + val) % MOD;
            }
        }
    }

    for (int i = 1; i < n_vertex; ++i) {
        cout << ans[i] << (i == n_vertex - 1 ? "" : " ");
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
