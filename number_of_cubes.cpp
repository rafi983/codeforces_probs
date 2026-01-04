#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

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

const int MAXN = 3000005;
long long fact[MAXN];
long long invFact[MAXN];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int a, b, c, k;
    if (!(cin >> a >> b >> c >> k)) return;
    vector<int> d(k);
    int g = 0;
    for (int i = 0; i < k; i++) {
        cin >> d[i];
        if (i == 0) g = d[i];
        else g = gcd(g, d[i]);
    }

    vector<int> divisors;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i * i != g) divisors.push_back(g / i);
        }
    }
    sort(divisors.begin(), divisors.end());

    int m = divisors.size();
    vector<long long> H(m);

    for (int i = 0; i < m; i++) {
        int S = divisors[i];
        long long val = (long long)gcd(S, a) * gcd(S, b);
        val %= MOD;
        val = (val * gcd(S, c)) % MOD;
        H[i] = val;
        for (int j = 0; j < i; j++) {
            if (S % divisors[j] == 0) {
                H[i] = (H[i] - H[j] + MOD) % MOD;
            }
        }
    }

    long long total_ans = 0;
    int total_cubes = a * b * c;

    for (int i = 0; i < m; i++) {
        if (H[i] == 0) continue;
        int S = divisors[i];

        long long num = fact[total_cubes / S];
        long long den = 1;
        for (int j = 0; j < k; j++) {
            den = (den * invFact[d[j] / S]) % MOD;
        }
        long long ways = (num * den) % MOD;

        total_ans = (total_ans + H[i] * ways) % MOD;
    }

    long long invTotal = modInverse(total_cubes % MOD);
    cout << (total_ans * invTotal) % MOD << "\n";
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

