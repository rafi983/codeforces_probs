#include <iostream>
#include <vector>
#include <map>

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

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long A = 1;
    map<int, long long> N;
    long long lazy_mul = 1;
    long long inv_mul = 1;
    long long inv3 = modInverse(3);
    int S = 0;

    for (int x : a) {
        if (x == 0) {
            A = (A * 3) % MOD;
            lazy_mul = (lazy_mul * 3) % MOD;
            inv_mul = (inv_mul * inv3) % MOD;
        } else {
            int T = S ^ x;

            long long val_T = 0;
            if (N.count(T)) val_T = (N[T] * lazy_mul) % MOD;

            long long val_S = 0;
            if (N.count(S)) val_S = (N[S] * lazy_mul) % MOD;

            long long next_A = (3 * val_T) % MOD;
            long long next_N_S = (A + 2 * val_T + val_S) % MOD;

            A = next_A;

            if (next_N_S == 0) {
                N.erase(S);
            } else {
                N[S] = (next_N_S * inv_mul) % MOD;
            }

            N.erase(T);

            S = T;
        }
    }

    long long sum_N = 0;
    for (auto const& [key, val] : N) {
        sum_N = (sum_N + val) % MOD;
    }
    sum_N = (sum_N * lazy_mul) % MOD;

    long long ans = (A + 3 * sum_N) % MOD;
    cout << ans << "\n";
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

