#include <iostream>
#include <vector>

using namespace std;

long long P = 1e9 + 7;
const int MAX_VAL = 100005;
long long fact[MAX_VAL];
long long invFact[MAX_VAL];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= P;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % P;
        base = (base * base) % P;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, P - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_VAL; i++) {
        fact[i] = (fact[i - 1] * i) % P;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr_large_n(long long n, int r) {
    if (r < 0) return 0;
    if (r == 0) return 1;

    long long numerator = 1;
    for (int i = 0; i < r; i++) {
        numerator = (numerator * ((n - i + P) % P)) % P;
    }

    return (numerator * invFact[r]) % P;
}

void solve() {
    long long a, b, k;
    if (!(cin >> a >> b >> k)) return;

    // n = k * (a - 1) + 1
    long long n_val = (k * (a - 1)) % P;
    n_val = (n_val + 1) % P;

    // m = k * C(n, a) * (b - 1) + 1
    long long ways = nCr_large_n(n_val, a);
    long long term = (k * ways) % P;
    term = (term * (b - 1)) % P;
    long long m_val = (term + 1) % P;

    cout << n_val << " " << m_val << "\n";
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

