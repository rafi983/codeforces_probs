#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 200005;
vector<int> primes;
bool is_prime[MAXN];

void sieve() {
    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAXN; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAXN; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < MAXN; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}

void solve() {
    int n;
    cin >> n;
    set<int> U;
    for (int i = 1; i <= n; ++i) U.insert(i);

    vector<int> p_out;
    p_out.reserve(n);
    long long S = 0;

    for (int i = 1; i <= n; ++i) {
        long long min_S = S + *U.begin();
        long long max_S = S + *U.rbegin();

        long long min_c = (min_S + i - 1) / i;
        long long max_c = (max_S + i - 1) / i;

        int best_x = -1;

        // Find primes in [min_c, max_c] descending
        auto it = upper_bound(primes.begin(), primes.end(), max_c);

        while (it != primes.begin()) {
            --it;
            int p_val = *it;
            if (p_val < min_c) break;

            // i*(p_val-1) - S < x <= i*p_val - S
            long long R_limit = (long long)i * p_val - S;
            long long L_limit = (long long)i * (p_val - 1) - S;

            auto u_it = U.upper_bound(R_limit);
            if (u_it != U.begin()) {
                --u_it;
                int candidate = *u_it;
                if (candidate > L_limit) {
                    best_x = candidate;
                    break;
                }
            }
        }

        if (best_x == -1) {
            best_x = *U.begin();
        }

        p_out.push_back(best_x);
        U.erase(best_x);
        S += best_x;
    }

    for (int i = 0; i < n; ++i) {
        cout << p_out[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
