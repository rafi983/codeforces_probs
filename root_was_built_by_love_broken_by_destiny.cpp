#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fact[200005];
const int MOD = 1000000007;

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    if (m != n - 1) {
        cout << 0 << "\n";
        return;
    }

    // Check connectivity
    int connected_cnt = 0;
    vector<bool> visited(n + 1, false);
    vector<int> q;
    q.reserve(n);
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

    if (connected_cnt != n) {
        cout << 0 << "\n";
        return;
    }

    // Identify spine
    vector<int> spine_nodes;
    vector<bool> is_spine(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (degree[i] > 1) {
            spine_nodes.push_back(i);
            is_spine[i] = true;
        }
    }

    if (spine_nodes.empty()) {
        // K2 case
        cout << 2 << "\n";
        return;
    }

    // Check if spine is a path
    for (int u : spine_nodes) {
        int spine_deg = 0;
        for (int v : adj[u]) {
            if (is_spine[v]) {
                spine_deg++;
            }
        }
        if (spine_deg > 2) {
            cout << 0 << "\n";
            return;
        }
    }

    long long ans = 1;
    if (spine_nodes.size() == 1) {
        ans = 2;
    } else {
        ans = 4;
    }

    for (int u : spine_nodes) {
        int leaf_neighbors = 0;
        for (int v : adj[u]) {
            if (!is_spine[v]) {
                leaf_neighbors++;
            }
        }
        ans = (ans * fact[leaf_neighbors]) % MOD;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

