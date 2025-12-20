#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MOD = 1e9 + 7;

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

long long P[35];
long long pow2[35];

void precompute() {
    P[1] = 1;
    for (int i = 2; i <= 32; ++i) {
        long long term = (P[i-1] * P[i-1]) % MOD;
        term = (term * i) % MOD;
        term = (term * modInverse(i-1)) % MOD;
        P[i] = term;
    }

    pow2[0] = 1;
    for (int i = 1; i <= 32; ++i) {
        pow2[i] = pow2[i-1] * 2;
    }
}

long long current_score = 1;

void solve_recursive(long long n, long long &k) {
    if (k == 0) return;

    // Operation: pick n
    current_score = (current_score * (n % MOD)) % MOD;
    k--;

    if (k == 0) return;

    // Process 1, 2, ..., n-1
    for (int j = 1; ; ++j) {
        if (j >= n) break;

        long long size = -1;
        if (j <= 32) size = pow2[j-1];

        if (size != -1 && k >= size) {
            current_score = (current_score * P[j]) % MOD;
            k -= size;
        } else {
            solve_recursive(j, k);
            return;
        }

        if (k == 0) return;
    }
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s.begin(), s.end());

    current_score = 1;

    for (long long val : s) {
        if (k == 0) break;

        long long size = -1;
        if (val <= 32) size = pow2[val-1];

        if (size != -1 && k >= size) {
            current_score = (current_score * P[val]) % MOD;
            k -= size;
        } else {
            solve_recursive(val, k);
            break;
        }
    }
    cout << current_score << "\n";
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

