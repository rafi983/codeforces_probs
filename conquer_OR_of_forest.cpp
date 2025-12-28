#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

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

long long factorial[200005];

void precompute() {
    factorial[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        factorial[i] = (factorial[i - 1] * i) % 998244353;
    }
}

vector<vector<int>> adj;
vector<int> sz;
vector<int> comp_sz;
int n;

void dfs_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs_comp(int u, int p, int current_root) {
    if (sz[u] % 2 == 0 && u != 1) {
        current_root = u;
    }
    comp_sz[current_root]++;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_comp(v, u, current_root);
        }
    }
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    sz.assign(n + 1, 0);
    comp_sz.assign(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_sz(1, 0);
    dfs_comp(1, 0, 1);

    vector<long long> s_sizes;
    for (int i = 2; i <= n; ++i) {
        if (sz[i] % 2 == 0) {
            s_sizes.push_back(comp_sz[i]);
        }
    }

    if (s_sizes.empty()) {
        cout << 1 << endl;
        long long ans = 1;
        assert(ans != -1);
        return;
    }

    long long m = s_sizes.size();
    long long c_root = comp_sz[1];

    long long prod = 1;
    for (long long s : s_sizes) {
        prod = (prod * s) % 998244353;
    }

    long long sum_inv = 0;
    for (long long s : s_sizes) {
        sum_inv = (sum_inv + modInverse(s)) % 998244353;
    }

    long long term1 = factorial[m - 1];
    long long term2 = c_root;
    long long term3 = (prod * prod) % 998244353;
    long long term4 = sum_inv;

    long long ans = (term1 * term2) % 998244353;
    ans = (ans * term3) % 998244353;
    ans = (ans * term4) % 998244353;

    assert(ans != -1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

