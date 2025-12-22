#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_ops = INF;

    // Preallocate vectors to avoid reallocation overhead
    vector<pair<int, int>> L(n + 1);
    vector<pair<int, int>> R(n + 1);

    for (int m = 0; m < n - 1; ++m) {

        int cur_min = a[m];
        int cur_max = a[m];
        L[1] = {cur_min, cur_max};
        for (int k = 2; k <= m + 1; ++k) {
            int val = a[m - k + 1];
            cur_min = min(cur_min, val);
            cur_max = max(cur_max, val);
            L[k] = {cur_min, cur_max};
        }

        // Build R intervals (going forwards from m+1)
        // R[j] corresponds to prefix of length j starting at m+1: a[m+1 ... m+j]
        cur_min = a[m + 1];
        cur_max = a[m + 1];
        R[1] = {cur_min, cur_max};
        for (int j = 2; j <= n - 1 - m; ++j) {
            int val = a[m + j];
            cur_min = min(cur_min, val);
            cur_max = max(cur_max, val);
            R[j] = {cur_min, cur_max};
        }

        int max_j = n - 1 - m;
        int j = max_j;

        for (int k = 1; k <= m + 1; ++k) {
            // Pruning: if k alone is already too large
            if (k - 1 >= min_ops) break;

            auto check = [&](int k_idx, int j_idx) {
                int l_min = L[k_idx].first;
                int l_max = L[k_idx].second;
                int r_min = R[j_idx].first;
                int r_max = R[j_idx].second;
                return max(l_min, r_min) <= min(l_max, r_max) + 1;
            };

            if (!check(k, j)) {
                continue;
            }

            // Try to decrease j
            while (j > 1 && check(k, j - 1)) {
                j--;
            }

            min_ops = min(min_ops, k + j - 2);
            if (min_ops == 0) {
                cout << 0 << "\n";
                return;
            }
        }
    }

    if (min_ops == INF) {
        cout << -1 << "\n";
    } else {
        cout << min_ops << "\n";
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

