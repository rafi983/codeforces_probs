#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VAL = 400005;
bool is_prime[MAX_VAL];

void sieve() {
    fill(is_prime, is_prime + MAX_VAL, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_VAL; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_VAL; i += p)
                is_prime[i] = false;
        }
    }
}

int n;
vector<vector<int>> adj;
vector<int> ans;
int current_val;

void dfs(int u, int p) {
    ans[u] = current_val;
    current_val++;

    for (int v : adj[u]) {
        if (v == p) continue;

        while (current_val < MAX_VAL && is_prime[current_val - ans[u]]) {
            current_val++;
        }
        dfs(v, u);
    }
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    ans.assign(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    current_val = 1;
    dfs(1, 0);

    if (current_val - 1 > 2 * n) {
        cout << -1 << "\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

