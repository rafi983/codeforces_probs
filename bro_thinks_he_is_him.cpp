#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 998244353;

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

struct FenwickTree {
    int n;
    vector<long long> tree;

    FenwickTree(int size) : n(size), tree(size + 1, 0) {}

    void add(int idx, long long delta) {
        delta %= MOD;
        if (delta < 0) delta += MOD;
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] = (tree[idx] + delta) % MOD;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum = (sum + tree[idx]) % MOD;
        }
        return sum;
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        long long res = (query(r) - query(l - 1)) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int q;
    if (!(cin >> q)) return;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) cin >> queries[i];

    vector<long long> pow2(n + 1);
    vector<long long> invPow2(n + 1);
    long long p2 = 1;
    long long inv2 = modInverse(2);
    long long ip2 = 1;

    for (int i = 0; i <= n; ++i) {
        pow2[i] = p2;
        invPow2[i] = ip2;
        p2 = (p2 * 2) % MOD;
        ip2 = (ip2 * inv2) % MOD;
    }

    FenwickTree ft1(n); // Stores s[i] * 2^i
    FenwickTree ft2(n); // Stores sigma[i] * 2^{-i}

    long long P = 0;
    long long current_p0 = 0;
    long long current_p1 = 0;

    // 1-based indexing for logic
    for (int i = 1; i <= n; ++i) {
        int val = s[i-1] - '0';

        // Update FT1
        if (val == 1) {
            ft1.add(i, pow2[i]);
        }

        // Update FT2
        // sigma = 1 if 0, -1 if 1
        long long sigma = (val == 0 ? 1 : -1);
        long long term2 = (sigma * invPow2[i]) % MOD;
        if (term2 < 0) term2 += MOD;
        ft2.add(i, term2);

        // Calculate initial P
        long long term;
        if (val == 0) {
            term = (invPow2[i] * current_p1) % MOD;
            current_p0 = (current_p0 + pow2[i]) % MOD;
        } else {
            term = (invPow2[i] * current_p0) % MOD;
            current_p1 = (current_p1 + pow2[i]) % MOD;
        }
        P = (P + term) % MOD;
    }

    for (int k : queries) {
        // k is 1-based index
        int idx = k - 1;
        int old_val = s[idx] - '0';
        int new_val = 1 - old_val;
        s[idx] = new_val + '0';

        // Calculate Delta1 (change at index k)
        long long p1_prev = ft1.query(k - 1);
        long long p0_prev = (pow2[k] - 2 - p1_prev) % MOD;
        // Note: sum_{i=1}^{k-1} 2^i = 2^k - 2.
        if (p0_prev < 0) p0_prev += MOD;

        long long delta1;
        if (old_val == 0) { // 0 -> 1

            delta1 = (invPow2[k] * (p0_prev - p1_prev)) % MOD;
        } else { // 1 -> 0

            delta1 = (invPow2[k] * (p1_prev - p0_prev)) % MOD;
        }
        if (delta1 < 0) delta1 += MOD;

        // Calculate Delta2 (change for j > k)
        long long suffix_sum = ft2.query(k + 1, n);
        long long delta2;
        if (old_val == 0) { // 0 -> 1
            delta2 = (pow2[k] * suffix_sum) % MOD;
        } else { // 1 -> 0
            delta2 = (-pow2[k] * suffix_sum) % MOD;
        }
        if (delta2 < 0) delta2 += MOD;

        P = (P + delta1 + delta2) % MOD;

        long long ft1_delta = (new_val == 1 ? pow2[k] : -pow2[k]);
        ft1.add(k, ft1_delta);


        long long old_sigma = (old_val == 0 ? 1 : -1);
        long long ft2_delta = (-2 * old_sigma * invPow2[k]) % MOD;
        ft2.add(k, ft2_delta);

        // Output answer
        long long ans = (pow2[n] - 1 + pow2[n-1] * P) % MOD;
        cout << ans << " ";
    }
    cout << endl;
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

