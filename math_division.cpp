#include <iostream>
#include <string>

using namespace std;

long long M = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= M;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, M - 2);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    long long x = 0;
    for (char c : s) {
        x = (x * 2 + (c - '0')) % M;
    }

    // Formula: (n - 2 + x * 2^{-(n-1)}) % M

    long long term1 = (n - 2) % M;
    if (term1 < 0) term1 += M;

    long long inv2 = modInverse(2);
    long long inv2_pow = power(inv2, n - 1);

    long long term2 = (x * inv2_pow) % M;

    long long ans = (term1 + term2) % M;
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

