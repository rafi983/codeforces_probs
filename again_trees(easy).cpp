#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

long long MOD = 1e9 + 7;

int n, k;
vector<vector<int>> adj;
vector<long long> a;
vector<long long> b;
vector<long long> S_vals;
vector<long long> T; // Subtree XOR sums

// dp[u][idx] : count
vector<vector<long long>> dp;

void dfs(int u, int p) {
    T[u] = a[u];

    int zero_idx = -1;
    for(int i=0; i<S_vals.size(); ++i) if(S_vals[i] == 0) zero_idx = i;

    // Allocate DP for u
    dp[u].assign(S_vals.size(), 0);
    if(zero_idx != -1) dp[u][zero_idx] = 1;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        T[u] ^= T[v];

        vector<long long> next_dp(S_vals.size(), 0);

        // Calculate W_cut
        long long w_cut = 0;
        for (int i = 0; i < S_vals.size(); ++i) {
            long long val = T[v] ^ S_vals[i];
            // Check if val is in B
            bool in_b = false;
            for (long long x : b) if (x == val) { in_b = true; break; }
            if (in_b) {
                w_cut = (w_cut + dp[v][i]) % MOD;
            }
        }

        for (int i_u = 0; i_u < S_vals.size(); ++i_u) {
            if (dp[u][i_u] == 0) continue;

            // Branch 1: Cut
            if (w_cut > 0) {
                long long s_new_val = S_vals[i_u] ^ T[v];
                int idx_new = -1;
                for(int z=0; z<S_vals.size(); ++z) if(S_vals[z] == s_new_val) { idx_new = z; break; }

                if (idx_new != -1) {
                    long long ways = (dp[u][i_u] * w_cut) % MOD;
                    next_dp[idx_new] = (next_dp[idx_new] + ways) % MOD;
                }
            }

            for (int i_v = 0; i_v < S_vals.size(); ++i_v) {
                if (dp[v][i_v] == 0) continue;

                long long s_new_val = S_vals[i_u] ^ S_vals[i_v];
                int idx_new = -1;
                for(int z=0; z<S_vals.size(); ++z) if(S_vals[z] == s_new_val) { idx_new = z; break; }

                if (idx_new != -1) { // Should always be found since S is closed under XOR
                   long long ways = (dp[u][i_u] * dp[v][i_v]) % MOD;
                   next_dp[idx_new] = (next_dp[idx_new] + ways) % MOD;
                }
            }
        }
        dp[u] = next_dp;
    }
}

void solve() {
    if (!(cin >> n >> k)) return;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    b.resize(k);
    for (int i = 0; i < k; ++i) cin >> b[i];

    // Generate S
    set<long long> s_set;
    for (int m = 0; m < (1 << k); ++m) {
        long long val = 0;
        for (int i = 0; i < k; ++i) {
            if ((m >> i) & 1) val ^= b[i];
        }
        s_set.insert(val);
    }
    S_vals.assign(s_set.begin(), s_set.end());

    T.assign(n + 1, 0);
    dp.assign(n + 1, vector<long long>());

    dfs(1, 0);

    long long ans = 0;
    // Final check for root
    for (int i = 0; i < S_vals.size(); ++i) {
        long long val = T[1] ^ S_vals[i];
        // Check if val in B
        bool in_b = false;
        for (long long x : b) if (x == val) { in_b = true; break; }
        if (in_b) {
            ans = (ans + dp[1][i]) % MOD;
        }
    }

    cout << ans << endl;
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
