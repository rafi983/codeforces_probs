#include <iostream>

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

void solve() {
    long long n, m;
    int k;
    if (!(cin >> n >> m >> k)) return;

    long long size_rel = 2 * n + 2 * m - 8;
    long long fixed_relevant_count = 0;
    long long current_sum_relevant = 0;

    for (int i = 0; i < k; ++i) {
        long long r, c;
        int color;
        cin >> r >> c >> color;

        bool is_row_boundary = (r == 1 || r == n);
        bool is_col_boundary = (c == 1 || c == m);


        if (is_row_boundary != is_col_boundary) {
            fixed_relevant_count++;
            if (color == 1) {
                current_sum_relevant++;
            }
        }
    }

    long long free_relevant = size_rel - fixed_relevant_count;

    long long mod_exp = MOD - 1;
    long long n_mod = n % mod_exp;
    long long m_mod = m % mod_exp;
    long long total_cells_mod = (n_mod * m_mod) % mod_exp;
    long long k_mod = k % mod_exp;
    long long total_free_mod = (total_cells_mod - k_mod + mod_exp) % mod_exp;

    if (free_relevant > 0) {
        long long exp = (total_free_mod - 1 + mod_exp) % mod_exp;
        cout << power(2, exp) << "\n";
    } else {
        if (current_sum_relevant % 2 != 0) {
            cout << "0\n";
        } else {
            cout << power(2, total_free_mod) << "\n";
        }
    }
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
