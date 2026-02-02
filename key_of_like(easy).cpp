#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 1000000007 - 2);
}

void solve() {
    int n, l, k_dummy;
    if (!(cin >> n >> l >> k_dummy)) return;


    vector<long long> E(n, 0);

    long long MOD = 1000000007;

    for (int i = 1; i <= l; ++i) {


        long long q = i / n;
        long long r = i % n;

        long long sum_prev = (i - 1) % MOD;
        long long full_cycles_contrib = (q % MOD * sum_prev) % MOD;


        vector<long long> window_sum(n, 0);
        if (r > 0) {
            long long current_window = 0;
            // Initial window for j=0: indices -1 ... -r => n-1 ... n-r
            for (int k = 1; k <= r; ++k) {
                current_window = (current_window + E[(n - k) % n]) % MOD;
            }
            window_sum[0] = current_window;

            // Slide
            for (int j = 1; j < n; ++j) {


                long long remove_idx = (j - 1 - r);
                while (remove_idx < 0) remove_idx += n;
                remove_idx %= n;

                long long add_idx = (j - 1 + n) % n;

                current_window = (current_window - E[remove_idx] + MOD) % MOD;
                current_window = (current_window + E[add_idx]) % MOD;
                window_sum[j] = current_window;
            }
        }

        // Construct next_E
        long long inv_i = modInverse(i);

        vector<long long> new_E(n);
        for (int j = 0; j < n; ++j) {
            long long val = 0;

            // Point contribution
            long long points = q % MOD;
            if (j < r) points = (points + 1) % MOD;

            val = (val + points) % MOD;

            // Recursive E contribution
            val = (val + full_cycles_contrib) % MOD;
            if (r > 0) {
                val = (val + window_sum[j]) % MOD;
            }

            new_E[j] = (val * inv_i) % MOD;
        }

        E = new_E;
    }

    for (int j = 0; j < n; ++j) {
        cout << E[j] << (j == n - 1 ? "" : " ");
    }
    cout << "\n";
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
