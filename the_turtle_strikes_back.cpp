#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long current = a[i * m + j];
            long long max_prev = -INF;
            if (i == 0 && j == 0) {
                max_prev = 0;
            } else {
                if (i > 0) max_prev = max(max_prev, dp[(i - 1) * m + j]);
                if (j > 0) max_prev = max(max_prev, dp[i * m + (j - 1)]);
            }
            dp[i * m + j] = max_prev + current;
        }
    }

    int num_diagonals = n + m - 1;
    vector<long long> best1(num_diagonals, -INF);
    vector<long long> best2(num_diagonals, -INF);

    vector<long long> rev_dp(n * m);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            long long current = a[i * m + j];
            long long max_next = -INF;
            if (i == n - 1 && j == m - 1) {
                max_next = 0;
            } else {
                if (i < n - 1) max_next = max(max_next, rev_dp[(i + 1) * m + j]);
                if (j < m - 1) max_next = max(max_next, rev_dp[i * m + (j + 1)]);
            }
            rev_dp[i * m + j] = max_next + current;

            long long path_val = dp[i * m + j] + rev_dp[i * m + j] - current;

            dp[i * m + j] = path_val;

            int diag = i + j;
            if (path_val > best1[diag]) {
                best2[diag] = best1[diag];
                best1[diag] = path_val;
            } else if (path_val > best2[diag]) {
                best2[diag] = path_val;
            }
        }
    }


    long long min_max_pleasure = INF;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long current_val = a[i * m + j];
            long long path_through_me = dp[i * m + j];
            int diag = i + j;

            long long val1 = path_through_me - 2 * current_val;

            long long val2 = -INF;
            if (path_through_me == best1[diag]) {
                val2 = best2[diag];
            } else {
                val2 = best1[diag];
            }

            long long michelangelo_outcome = max(val1, val2);

            min_max_pleasure = min(min_max_pleasure, michelangelo_outcome);
        }
    }

    cout << min_max_pleasure << "\n";
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

