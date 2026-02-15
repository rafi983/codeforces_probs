#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

long long solve_1d(int n, int m, const vector<long long>& costs, const vector<vector<int>>& grid) {
    vector<vector<long long>> dp(n, vector<long long>(2, INF));

    dp[0][0] = 0;
    dp[0][1] = costs[0];

    for (int i = 0; i < n - 1; ++i) {
        bool allowed[2][2] = {{true, true}, {true, true}};

        for (int j = 0; j < m; ++j) {
            int diff = grid[i+1][j] - grid[i][j];

            if (diff == 0) {
                allowed[0][0] = false;
                allowed[1][1] = false;
            }
            else if (diff == 1) {
                allowed[1][0] = false;
            }
            else if (diff == -1) {
                allowed[0][1] = false;
            }
        }

        for (int cur = 0; cur <= 1; ++cur) {
            if (dp[i][cur] == INF) continue;
            for (int next = 0; next <= 1; ++next) {
                if (allowed[cur][next]) {
                    long long cost = (next == 1 ? costs[i+1] : 0);
                    dp[i+1][next] = min(dp[i+1][next], dp[i][cur] + cost);
                }
            }
        }
    }

    long long ans = min(dp[n-1][0], dp[n-1][1]);
    return (ans == INF ? -1 : ans);
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> h(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
        }
    }

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long row_cost = solve_1d(n, n, a, h);
    if (row_cost == -1) {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> h_T(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            h_T[i][j] = h[j][i];
        }
    }

    long long col_cost = solve_1d(n, n, b, h_T);
    if (col_cost == -1) {
        cout << -1 << "\n";
        return;
    }

    cout << row_cost + col_cost << "\n";
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

