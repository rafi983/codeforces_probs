#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<long long> dp(m, INF);

    {
        vector<long long> B(2 * m);
        for (int j = 0; j < m; ++j) B[j] = B[j + m] = a[0][j];

        vector<long long> P(2 * m + 1, 0);
        for (int j = 0; j < 2 * m; ++j) P[j + 1] = P[j] + B[j];

        for (int j_prime = 0; j_prime < m; ++j_prime) {
            long long min_cost = INF;
            for (int s = 0; s < m; ++s) {
                long long current_sum = P[s + j_prime + 1] - P[s];
                long long cost = k * s + current_sum;
                if (cost < min_cost) min_cost = cost;
            }
            dp[j_prime] = min_cost;
        }
    }

    for (int i = 1; i < n; ++i) {
        vector<long long> next_dp(m, INF);

        vector<long long> B(2 * m);
        for (int j = 0; j < m; ++j) B[j] = B[j + m] = a[i][j];

        vector<long long> P(2 * m + 1, 0);
        for (int j = 0; j < 2 * m; ++j) P[j + 1] = P[j] + B[j];

        for (int s = 0; s < m; ++s) {
            long long current_min_prev = INF;
            for (int j_prime = 0; j_prime < m; ++j_prime) {
                long long val = dp[j_prime] - P[j_prime + s];
                if (val < current_min_prev) current_min_prev = val;

                long long cost = k * s + P[j_prime + 1 + s] + current_min_prev;
                if (cost < next_dp[j_prime]) next_dp[j_prime] = cost;
            }
        }
        dp = next_dp;
    }

    cout << dp[m - 1] << endl;
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

