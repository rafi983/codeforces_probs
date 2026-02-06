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

const int MOD = 998244353;
const int G = 3;

void ntt(vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = power(G, (MOD - 1) / len);
        if (invert)
            wlen = modInverse(wlen);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v < MOD ? u + v : u + v - MOD);
                a[i + j + len / 2] = (u - v >= 0 ? u - v : u - v + MOD);
                w = (w * wlen) % MOD;
            }
        }
    }
    if (invert) {
        long long n_inv = modInverse(n);
        for (int& x : a)
            x = (x * n_inv) % MOD;
    }
}

// Polynomial Inversion mod x^d
vector<int> inverse(const vector<int>& a, int d) {
    if (a.empty() || a[0] == 0) return {};
    vector<int> b = { (int)modInverse(a[0]) };
    int k = 1;
    while (k < d) {
        int next_k = 2 * k;
        int sz_a = min((int)a.size(), next_k);
        vector<int> a_sub(a.begin(), a.begin() + sz_a);
        a_sub.resize(2 * next_k, 0);

        vector<int> b_curr = b;
        b_curr.resize(2 * next_k, 0);

        ntt(a_sub, false);
        ntt(b_curr, false);

        for (int i = 0; i < 2 * next_k; i++) {
            long long term = (1LL * a_sub[i] * b_curr[i]) % MOD;
            long long factor = (2 - term + MOD) % MOD;
            b_curr[i] = (1LL * b_curr[i] * factor) % MOD;
        }

        ntt(b_curr, true);
        b_curr.resize(next_k);
        b = b_curr;
        k = next_k;
    }
    b.resize(d);
    return b;
}

const int MAXN = 200005;
long long fact[2*MAXN], invFact[2*MAXN];
long long inv16[MAXN];

void precompute_factorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < 2*MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[2*MAXN - 1] = modInverse(fact[2*MAXN - 1]);
    for (int i = 2*MAXN - 2; i >= 1; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;

    long long i16 = modInverse(16);
    inv16[0] = 1;
    for(int i=1; i<MAXN; ++i) inv16[i] = (inv16[i-1] * i16) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

long long S[MAXN];
long long SS[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials();

    int limit_n = 200000;
    int limit_k = limit_n / 2;

    vector<int> u_poly(limit_k + 1);
    for(int k=0; k<=limit_k; ++k) {
        long long bin = nCr(2*k, k);
        long long term = (bin * bin) % MOD;
        term = (term * inv16[k]) % MOD;
        u_poly[k] = term;
    }

    vector<int> v_poly = inverse(u_poly, limit_k + 1);

    S[0] = v_poly[0];
    SS[0] = 0;

    for(int i=1; i<=limit_k; ++i) {
        S[i] = (S[i-1] + v_poly[i]) % MOD;
        SS[i] = (SS[i-1] + 1LL * 2 * i * v_poly[i]) % MOD;
    }

    int t;
    if (cin >> t) {
        while(t--) {
            int n;
            cin >> n;
            int m = n / 2;
            long long ans = 0;
            // E = (n + 1) * S_m - SS_m
            long long term1 = (1LL * (n + 1) * S[m]) % MOD;
            long long term2 = SS[m];
            ans = (term1 - term2 + MOD) % MOD;
            cout << ans << "\n";
        }
    }
    return 0;
}
