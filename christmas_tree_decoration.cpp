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

long long fact[100];
long long invFact[100];

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= 60; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void zaman() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n + 1);
    long long sum = 0;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    long long q = sum / n;
    long long rem = sum % n;

    int forced_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > q + 1) {
            cout << 0 << endl;
            return;
        }
        if (a[i] == q + 1) {
            forced_count++;
        }
    }

    if (forced_count > rem) {
        cout << 0 << endl;
        return;
    }

    long long ways = nCr(n - forced_count, rem - forced_count);
    long long p1 = fact[rem];
    long long p2 = fact[n - rem];

    long long ans = ways * p1 % MOD;
    ans = ans * p2 % MOD;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }
    return 0;
}
