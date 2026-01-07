#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 400005;

int n;
int a[MAXN];
vector<int> adj[MAXN];
int partner[MAXN];

int tin[MAXN], tout[MAXN], timer;
int sub_internal_pairs[MAXN]; // Count of fully contained pairs in subtree
int pairs_at_lca[MAXN]; // Count of pairs whose LCA is this node
int up[MAXN][20];
int depth[MAXN];

void dfs_prep(int root, const vector<vector<int>>& tree_adj) {
    fill(tin, tin + 2 * n + 1, 0);
    timer = 0;
    vector<int> stk;
    stk.reserve(2 * n);
    stk.push_back(root);

    while(!stk.empty()) {
        int u = stk.back();
        if(tin[u] == 0) {
            tin[u] = ++timer;
            sub_internal_pairs[u] = pairs_at_lca[u];
            if(!tree_adj[u].empty()) {
                for(auto it = tree_adj[u].rbegin(); it != tree_adj[u].rend(); ++it) {
                    stk.push_back(*it);
                }
            }
        } else {
            stk.pop_back();
            tout[u] = timer;
            for(int v : tree_adj[u]) {
                sub_internal_pairs[u] += sub_internal_pairs[v];
            }
        }
    }
}

struct Fenwick {
    int size;
    vector<int> tree;
    void init(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }
    void add(int idx, int val) {
        for (; idx <= size; idx += idx & -idx) tree[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += tree[idx];
        return sum;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

struct Solution {
    vector<int> kept_nodes;
    bool valid;
};

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

Solution solve_rooted(int root) {
    timer = 0;
    // Build rooted tree structure
    vector<vector<int>> tree_adj(2 * n + 1);
    vector<int> parent(2 * n + 1, 0);
    vector<int> order;
    vector<int> q_bfs;
    q_bfs.push_back(root);
    vector<bool> vis_bfs(2 * n + 1, false);
    vis_bfs[root] = true;

    int head = 0;
    while(head < q_bfs.size()){
        int u = q_bfs[head++];
        for(int v : adj[u]){
            if(!vis_bfs[v]){
                vis_bfs[v] = true;
                tree_adj[u].push_back(v);
                parent[v] = u;
                q_bfs.push_back(v);
            }
        }
    }

    for(int i=0; i<=2*n; ++i) pairs_at_lca[i] = 0;

    fill(tin, tin + 2 * n + 1, 0);
    timer = 0;

    vector<int> stk_lca;
    stk_lca.reserve(2*n);
    stk_lca.push_back(root);

    while(!stk_lca.empty()){
        int u = stk_lca.back();
        if(tin[u] == 0) {
            tin[u] = ++timer;
            if (u == root) {
                depth[u] = 0;
                up[u][0] = u;
            } else {
                int p = parent[u];
                depth[u] = depth[parent[u]] + 1;
                up[u][0] = p;
            }
            for(int i=1; i<20; ++i)
                up[u][i] = up[up[u][i-1]][i-1];

            if(!tree_adj[u].empty()){
                for(auto it = tree_adj[u].rbegin(); it != tree_adj[u].rend(); ++it){
                    stk_lca.push_back(*it);
                }
            }
        } else {
            stk_lca.pop_back();
            tout[u] = timer;
        }
    }

    auto get_lca = [&](int u, int v) {
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(int i=19; i>=0; --i) {
            if(!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    };

    for(int c=1; c<=n; ++c) {
    }

    vector<bool> processed_color(n + 1, false);
    for(int i=1; i<=2*n; ++i) {
        int c = a[i];
        if(processed_color[c]) continue;
        int u = i;
        int v = partner[i];
        processed_color[c] = true;
        int lca = get_lca(u, v);
        pairs_at_lca[lca]++;
    }

    dfs_prep(root, tree_adj);

    Fenwick removed_partners, kept_nodes;
    removed_partners.init(2*n);
    kept_nodes.init(2*n);

    vector<bool> is_removed(2*n + 1, false);
    vector<bool> is_kept(2*n + 1, false);

    for(int k = 2*n; k >= 1; --k) {
        if(is_removed[k]) continue;
        if(k == root) {
            is_kept[k] = true;
            kept_nodes.add(tin[k], 1);
            continue;
        }

        // Conditions
        bool no_internal = (sub_internal_pairs[k] == 0);
        bool no_removed_part = (removed_partners.query(tin[k], tout[k]) == 0);
        bool no_kept_nodes = (kept_nodes.query(tin[k], tout[k]) == 0);

        if(no_internal && no_removed_part && no_kept_nodes) {
            // Remove k and its subtree
            q_bfs.clear();
            q_bfs.push_back(k);
            head = 0;
            is_removed[k] = true;


            while(head < q_bfs.size()) {
                int u = q_bfs[head++];
                // Update partner
                int v = partner[u];
                removed_partners.add(tin[v], 1);

                for(int child : tree_adj[u]) {
                    if(!is_removed[child]) {
                        is_removed[child] = true;
                        q_bfs.push_back(child);
                    }
                }
            }
        } else {
            is_kept[k] = true;
            kept_nodes.add(tin[k], 1);
        }
    }

    Solution sol;
    sol.valid = true;
    for(int i=1; i<=2*n; ++i) {
        if(!is_removed[i]) sol.kept_nodes.push_back(i);
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for(int c=1; c<=n; ++c) {
        partner[pos[c][0]] = pos[c][1];
        partner[pos[c][1]] = pos[c][0];
    }

    for(int i=0; i<2*n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Try rooting at both positions of color 1.
    int r1 = pos[1][0];
    int r2 = pos[1][1];

    Solution s1 = solve_rooted(r1);
    Solution s2 = solve_rooted(r2);


    vector<int>& v1 = s1.kept_nodes;
    vector<int>& v2 = s2.kept_nodes;


    int i1 = v1.size() - 1;
    int i2 = v2.size() - 1;

    bool s1_better = false; // default s2 better or equal

    while(i1 >= 0 && i2 >= 0) {
        if(v1[i1] == v2[i2]) {
            i1--; i2--;
        } else if(v1[i1] > v2[i2]) {
            // v1 has a larger element. v1 is worse cost. s2 better.
            s1_better = false;
            break;
        } else {
            // v2 has larger. s1 better.
            s1_better = true;
            break;
        }
    }
    if(i1 < 0 && i2 >= 0) s1_better = true; // v1 empty, v2 has stuff
    else if(i2 < 0 && i1 >= 0) s1_better = false;

    vector<int>& ans = s1_better ? v1 : v2;

    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); ++i) {
        cout << ans[i] << (i == ans.size()-1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
