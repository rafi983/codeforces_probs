#include <iostream>
#include <vector>
#include <numeric>

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

struct NodeInfo {
    long long p; // prob exist
    long long q; // 1 - p

    int z_count = 0; // count of neighbors with q=0 (i.e. p=1)
    long long prod_nz = 1; // product of q for neighbors with q!=0
    long long sum_ratio = 0; // sum of p/q for neighbors with q!=0

    long long S0 = 0; // prob all neighbors 0
    long long S1 = 0; // prob exactly one neighbor 1

    long long E = 0; // Expected value of L_u
};

vector<NodeInfo> nodes;
vector<vector<int>> adj;

pair<long long, long long> get_excl(int u, int v) {
    long long pv = nodes[v].p;
    long long qv = nodes[v].q;

    int z = nodes[u].z_count;
    if (qv == 0) z--; // removing v reduces zero count

    if (z >= 2) return {0, 0};

    if (z == 1) {

        long long res = nodes[u].prod_nz;
        if (qv != 0) res = res * modInverse(qv) % MOD;
        return {0, res};
    }

    long long current_prod = nodes[u].prod_nz;
    if (qv != 0) {
        current_prod = current_prod * modInverse(qv) % MOD;
    }
    long long val0 = current_prod;

    long long current_sum = nodes[u].sum_ratio;
    if (qv != 0) {
        long long term = pv * modInverse(qv) % MOD;
        current_sum = (current_sum - term + MOD) % MOD;
    }
    long long val1 = val0 * current_sum % MOD;

    return {val0, val1};
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    nodes.assign(n + 1, {});
    adj.assign(n + 1, {});

    for (int i = 1; i <= n; ++i) {
        long long u, v;
        cin >> u >> v;
        long long p_fall = u * modInverse(v) % MOD;
        nodes[i].p = (1 - p_fall + MOD) % MOD;
        nodes[i].q = p_fall;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Pass 1: Build node stats
    for (int i = 1; i <= n; ++i) {
        for (int neighbor : adj[i]) {
            long long q = nodes[neighbor].q;
            long long p = nodes[neighbor].p;
            if (q == 0) {
                nodes[i].z_count++;
            } else {
                nodes[i].prod_nz = nodes[i].prod_nz * q % MOD;
                nodes[i].sum_ratio = (nodes[i].sum_ratio + p * modInverse(q)) % MOD;
            }
        }

        // Calculate S0, S1, E
        if (nodes[i].z_count == 0) {
            nodes[i].S0 = nodes[i].prod_nz;
            nodes[i].S1 = nodes[i].S0 * nodes[i].sum_ratio % MOD;
        } else if (nodes[i].z_count == 1) {
            nodes[i].S0 = 0;
            // S1: the zero-neighbor is 1, others 0
            nodes[i].S1 = nodes[i].prod_nz;
        } else {
            nodes[i].S0 = 0;
            nodes[i].S1 = 0;
        }

        nodes[i].E = nodes[i].p * nodes[i].S1 % MOD;
    }

    long long S = 0;
    long long sum_sq_E = 0;
    for (int i = 1; i <= n; ++i) {
        S = (S + nodes[i].E) % MOD;
        sum_sq_E = (sum_sq_E + nodes[i].E * nodes[i].E) % MOD;
    }

    long long base_pairs = (S * S % MOD - sum_sq_E + MOD) % MOD;

    long long adj_corr = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (u > v) continue;

            auto exc_u = get_excl(u, v);
            auto exc_v = get_excl(v, u);

            long long T = nodes[u].p * nodes[v].p % MOD * exc_u.first % MOD * exc_v.first % MOD;
            long long prod_E = nodes[u].E * nodes[v].E % MOD;

            long long cv = (T - prod_E + MOD) % MOD;
            adj_corr = (adj_corr + 2 * cv) % MOD;
        }
    }

    long long dist2_corr = 0;
    for (int w = 1; w <= n; ++w) {
        if (nodes[w].q == 0 || nodes[w].p == 0) continue;

        long long sum_D = 0;
        long long sum_sq_D = 0;

        for (int u : adj[w]) {
            auto exc = get_excl(u, w);
            // D_u = p_u * (Val1 - Val0)
            long long diff = (exc.second - exc.first + MOD) % MOD;
            long long D = nodes[u].p * diff % MOD;

            sum_D = (sum_D + D) % MOD;
            sum_sq_D = (sum_sq_D + D * D) % MOD;
        }

        long long pair_sum = (sum_D * sum_D % MOD - sum_sq_D + MOD) % MOD;

        long long factor = nodes[w].p * nodes[w].q % MOD;
        long long term = factor * pair_sum % MOD;

        dist2_corr = (dist2_corr + term) % MOD;
    }

    long long total = (base_pairs + adj_corr + dist2_corr) % MOD;
    long long ans = total * modInverse(2) % MOD;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
