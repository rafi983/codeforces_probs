#include <iostream>
#include <vector>

using namespace std;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

vector<vector<int>> tree_adj;
vector<int> col;
vector<int> sz;
vector<int> L, R, NodeAt;
int timer_dfs;
long long current_q_val;
BIT* bit_ptr;
long long term2_sum;

void dfs_sz(int u) {
    sz[u] = 1;
    L[u] = ++timer_dfs;
    NodeAt[timer_dfs] = u;
    for (int v : tree_adj[u]) {
        dfs_sz(v);
        sz[u] += sz[v];
    }
    R[u] = timer_dfs;
}

void dfs_dsu(int u, bool keep) {
    int mx = -1, bigChild = -1;
    for (int v : tree_adj[u]) {
        if (mx < sz[v]) {
            mx = sz[v];
            bigChild = v;
        }
    }

    for (int v : tree_adj[u]) {
        if (v != bigChild) {
            dfs_dsu(v, false);
        }
    }

    if (bigChild != -1) {
        dfs_dsu(bigChild, true);
    }

    auto add_node = [&](int x) {
        int c = col[x];
        int c1 = bit_ptr->query(c, bit_ptr->n);
        int c2 = bit_ptr->query(1, c);
        current_q_val += c1 + c2;
        bit_ptr->add(c, 1);
        current_q_val += 1;
    };

    for (int v : tree_adj[u]) {
        if (v != bigChild) {
            for(int i = L[v]; i <= R[v]; ++i) {
                add_node(NodeAt[i]);
            }
        }
    }
    add_node(u);

    term2_sum += current_q_val;

    if (!keep) {
        for(int i = L[u]; i <= R[u]; ++i) {
            int x = NodeAt[i];
            bit_ptr->add(col[x], -1);
        }
        current_q_val = 0;
    }
}

void zaman() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<pair<int, int>> extras(m);
    vector<int> M(n + 1);
    vector<vector<int>> rev_adj(n + 1);

    for (int i = 1; i < n; ++i) {
        M[i] = i + 1;
        rev_adj[i + 1].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        cin >> extras[i].first >> extras[i].second;
        int u = extras[i].first;
        int v = extras[i].second;
        if (v > M[u]) M[u] = v;
        rev_adj[v].push_back(u);
    }

    vector<int> D(n + 1, -1);
    vector<int> q_bfs;
    q_bfs.reserve(n);
    D[n] = 0;
    q_bfs.push_back(n);

    int head = 0;
    while(head < (int)q_bfs.size()){
        int u = q_bfs[head++];
        for(int v : rev_adj[u]){
            if(D[v] == -1){
                D[v] = D[u] + 1;
                q_bfs.push_back(v);
            }
        }
    }

    tree_adj.assign(n + 1, vector<int>());
    vector<int> d_depth(n + 1, 0);

    for(int i = n - 1; i >= 1; --i) {
        if (M[i] <= n) {
            d_depth[i] = d_depth[M[i]] + 1;
            tree_adj[M[i]].push_back(i);
        }
    }

    vector<long long> global_counts(n + 2, 0);
    for(int i = 1; i <= n; ++i) {
        if(D[i] != -1) global_counts[D[i] + 1]++;
    }

    vector<long long> suff(n + 3, 0);
    for(int i = n + 1; i >= 0; --i) {
        suff[i] = suff[i+1] + global_counts[i];
    }

    long long term1 = 0;
    long long total_pairs = 0;
    for(int y = 1; y <= n; ++y) {
        if (D[y] == -1) continue;
        int d_y = D[y];
        long long cnt = suff[d_y + 1];
        term1 += (long long)d_depth[y] * cnt;
        total_pairs += cnt;
    }

    col.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i) col[i] = D[i] + 1;
    sz.assign(n + 1, 0);
    L.assign(n + 1, 0);
    R.assign(n + 1, 0);
    NodeAt.assign(n + 1, 0);
    timer_dfs = 0;

    dfs_sz(n);

    bit_ptr = new BIT(n + 2);
    term2_sum = 0;
    current_q_val = 0;

    dfs_dsu(n, false);

    delete bit_ptr;

    long long ans = term1 - term2_sum + total_pairs;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            zaman();
        }
    }
    return 0;
}
