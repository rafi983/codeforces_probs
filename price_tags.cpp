#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    long long y;
    if (!(cin >> n >> y)) return;
    vector<int> c(n);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        max_val = max(max_val, c[i]);
    }

    vector<int> cnt(max_val + 1, 0);
    for (int x : c) {
        cnt[x]++;
    }

    vector<int> pref(max_val + 2, 0);
    for (int i = 0; i <= max_val; ++i) {
        pref[i+1] = pref[i] + cnt[i];
    }

    auto get_count = [&](int L, int R) {
        if (L > max_val) return 0;
        R = min(R, max_val);

        return pref[R+1] - pref[L+1];
    };

    long long max_income = -2e18; // Initialize with a very small number

    // Iterate x from 2 to max_val + 1
    for (int x = 2; x <= max_val + 1; ++x) {
        long long current_sum_prices = 0;
        long long current_reused = 0;


        for (int k = 1; ; ++k) {
            int L = (k - 1) * x;
            int R = k * x;

            if (L > max_val) break;

            int num = get_count(L, R);

            if (num > 0) {
                current_sum_prices += (long long)num * k;
                if (k <= max_val) {
                    current_reused += min(num, cnt[k]);
                }
            }
        }

        long long cost = (n - current_reused) * y;
        long long income = current_sum_prices - cost;
        max_income = max(max_income, income);
    }

    cout << max_income << endl;
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

