#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n, m, d;
    if (!(cin >> n >> m >> d)) return;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<int> dp(m, 0);

    vector<int> holds(m, 0);
    for(int j=0; j<m; ++j) {
        if(grid[n-1][j] == 'X') holds[j] = 1;
    }

    vector<int> hold_pref(m + 1, 0);
    for(int j=0; j<m; ++j) {
        hold_pref[j+1] = hold_pref[j] + holds[j];
    }

    auto get_hold_count = [&](int L, int R) {
        L = max(0, L);
        R = min(m - 1, R);
        if (L > R) return 0;
        return hold_pref[R + 1] - hold_pref[L];
    };

    for(int j=0; j<m; ++j) {
        if(grid[n-1][j] == 'X') {
            dp[j] = get_hold_count(j - d, j + d);
        } else {
            dp[j] = 0;
        }
    }

    // Iterate upwards
    for (int i = n - 2; i >= 0; --i) {
        vector<int> next_dp(m, 0);
        vector<int> incoming(m, 0);

        // Prefix sum of previous level DP
        vector<int> dp_pref(m + 1, 0);
        for(int j=0; j<m; ++j) {
            dp_pref[j+1] = (dp_pref[j] + dp[j]) % MOD;
        }

        auto get_dp_sum = [&](int L, int R) {
            L = max(0, L);
            R = min(m - 1, R);
            if (L > R) return 0;
            int res = dp_pref[R + 1] - dp_pref[L];
            if (res < 0) res += MOD;
            return res;
        };

        int max_dx = -1;
        long long d2_minus_1 = (long long)d * d - 1;
        if (d2_minus_1 >= 0) {
            max_dx = floor(sqrt(d2_minus_1));
        }

        // Calculate Incoming[j]
        for(int j=0; j<m; ++j) {
            if(grid[i][j] == 'X') {
                if (max_dx >= 0) {
                    incoming[j] = get_dp_sum(j - max_dx, j + max_dx);
                } else {
                    incoming[j] = 0;
                }
            }
        }

        // Prefix sum of Incoming
        vector<int> inc_pref(m + 1, 0);
        for(int j=0; j<m; ++j) {
            inc_pref[j+1] = (inc_pref[j] + incoming[j]) % MOD;
        }

        auto get_inc_sum = [&](int L, int R) {
            L = max(0, L);
            R = min(m - 1, R);
            if (L > R) return 0;
            int res = inc_pref[R + 1] - inc_pref[L];
            if (res < 0) res += MOD;
            return res;
        };

        // Calculate next_dp[j]
        for(int j=0; j<m; ++j) {
            if(grid[i][j] == 'X') {
                next_dp[j] = get_inc_sum(j - d, j + d);
            }
        }

        dp = next_dp;
    }

    int ans = 0;
    for(int x : dp) {
        ans = (ans + x) % MOD;
    }
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

