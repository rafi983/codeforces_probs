#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

vector<int> col_sum;
vector<int> total_mat;

void solve_zaman() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;
    vector<vector<int>> adj(n + 1);
    int edge_cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_cnt++;
    }

    int connected_cnt = 0;
    if (n > 0) {
        vector<int> q;
        vector<bool> visited(n + 1, false);
        q.push_back(1);
        visited[1] = true;
        int head = 0;
        while(head < q.size()){
            int u = q[head++];
            connected_cnt++;
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }
    }

    if (connected_cnt != n || edge_cnt != n - 1) {
        exit(0);
    }

    vector<vector<int>> children(n + 1);
    vector<int> parent(n + 1, 0);

    vector<int> q;
    vector<bool> visited(n + 1, false);
    q.push_back(1);
    visited[1] = true;
    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        for(int v : adj[u]){
            if(v != parent[u]){
                visited[v] = true;
                parent[v] = u;
                children[u].push_back(v);
                q.push_back(v);
            }
        }
    }

    vector<int> post_order;
    vector<int> stk;
    stk.push_back(1);
    while(!stk.empty()){
        int u = stk.back();
        stk.pop_back();
        post_order.push_back(u);
        for(int v : children[u]){
            stk.push_back(v);
        }
    }
    reverse(post_order.begin(), post_order.end());

    // Resize global arrays
    int size = (n + 1) * (n + 1);
    col_sum.assign(size, 0);
    total_mat.assign(size, 0);
    vector<int> row_sum(n + 1, 0);

    // Lambda to access flattened arrays
    auto idx = [&](int r, int c) { return r * (n + 1) + c; };

    for (int u : post_order) {

        fill(row_sum.begin(), row_sum.end(), 0);

        for (int v : post_order) {
            long long existing = 0;
            // existing(u, v) = sum total(c1, c2)
            for (int cu : children[u]) {
                for (int cv : children[v]) {
                    existing += total_mat[idx(cu, cv)];
                    if (existing >= 4000000000000000000LL) existing %= MOD;
                }
            }
            existing %= MOD;

            long long dp_val = 0;
            if (s[u - 1] == s[v - 1]) {
                dp_val = (1 + existing) % MOD;
            }

            // RowSum[v] = dp + sum(RowSum[child])
            long long current_row_sum = dp_val;
            for (int cv : children[v]) {
                current_row_sum += row_sum[cv];
                if (current_row_sum >= MOD) current_row_sum -= MOD;
            }
            row_sum[v] = current_row_sum;

            // ColSum[u][v] = dp + sum(ColSum[child][v])
            long long current_col_sum = dp_val;
            for (int cu : children[u]) {
                current_col_sum += col_sum[idx(cu, v)];
                if (current_col_sum >= MOD) current_col_sum -= MOD;
            }
            col_sum[idx(u, v)] = current_col_sum;

            // Total = Existing + RowSum + ColSum - DP
            long long tot = existing + current_row_sum;
            if (tot >= MOD) tot -= MOD;
            tot += current_col_sum;
            if (tot >= MOD) tot -= MOD;
            tot -= dp_val;
            if (tot < 0) tot += MOD;

            total_mat[idx(u, v)] = tot;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << total_mat[idx(i, i)] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve_zaman();
        }
    }
    return 0;
}
