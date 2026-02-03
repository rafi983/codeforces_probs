#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    vector<int> q;
    q.reserve(n);

    q.push_back(1);
    parent[1] = 0;

    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        order.push_back(u);
        for(int v : adj[u]){
            if(v != parent[u]){
                parent[v] = u;
                q.push_back(v);
            }
        }
    }

    vector<int> L(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        bool is_leaf = true;
        int min_child_L = 1e9; // Sufficiently large

        for (int v : adj[u]) {
            if (v != parent[u]) {
                is_leaf = false;
                if (L[v] < min_child_L) {
                    min_child_L = L[v];
                }
            }
        }

        if (is_leaf) {
            L[u] = 0;
        } else {
            L[u] = 1 + min_child_L;
        }
    }

    vector<long long> P(n + 1);
    P[1] = 1;

    // Process in forward order (top-down)
    for (int i = 0; i < n; ++i) {
        int u = order[i];
        if (u == 1) continue;

        long long num = L[u];
        long long den = L[u] + 1;
        long long fail_prob = modInverse(den);

        P[u] = (P[parent[u]] * num) % 998244353;
        P[u] = (P[u] * fail_prob) % 998244353;
    }

    for (int i = 1; i <= n; ++i) {
        cout << P[i] << (i == n ? "" : " ");
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
