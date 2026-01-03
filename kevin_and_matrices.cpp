#include "iostream"
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1000005;

long long fact[MAXN], invFact[MAXN];

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

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int n, v;
    long long m;
    cin >> n >> m >> v;

    long long total_ans = 0;

    vector<long long> v_pow(n + 1);
    v_pow[0] = 1;
    for(int i=1; i<=n; ++i) v_pow[i] = (v_pow[i-1] * v) % MOD;

    long long v_pow_m = power(v, m);
    long long v_pow_n = v_pow[n];
    long long v_nm = power(v_pow_n, m);

    vector<long long> Q_pow(n + 1);

    for (int k = 1; k <= v; ++k) {
        long long k_pow_m = power(k, m);
        long long termA = power((v_pow_m - k_pow_m + MOD) % MOD, n);

        long long Q = v - k + 1;

        Q_pow[0] = 1;
        for(int i=1; i<=n; ++i) Q_pow[i] = (Q_pow[i-1] * Q) % MOD;

        long long Q_pow_n = Q_pow[n];
        long long termB = power((v_pow_n - Q_pow_n + MOD) % MOD, m);

        long long intersection = 0;
        long long cur_k_pow = 1;

        for (int i = 0; i <= n; ++i) {
            long long val1 = cur_k_pow * v_pow[n - i] % MOD;
            long long val2 = Q_pow[n - i];
            long long diff = (val1 - val2 + MOD) % MOD;

            long long term = power(diff, m);
            long long ways = nCr(n, i) * term % MOD;

            if (i % 2 == 1) {
                intersection = (intersection - ways + MOD) % MOD;
            } else {
                intersection = (intersection + ways) % MOD;
            }

            cur_k_pow = (cur_k_pow * k) % MOD;
        }

        long long N_k = (v_nm - termA + MOD) % MOD;
        N_k = (N_k - termB + MOD) % MOD;
        N_k = (N_k + intersection) % MOD;

        total_ans = (total_ans + N_k) % MOD;
    }

    cout << total_ans << "\n";
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

