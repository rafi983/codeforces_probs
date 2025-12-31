#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    string s;
    cin >> s;
    vector<vector<long long>> a(n, vector<long long>(m));
    vector<long long> row_sum(n, 0);
    vector<long long> col_sum(m, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            row_sum[i] += a[i][j];
            col_sum[j] += a[i][j];
        }
    }

    int r = 0, c = 0;
    for (char move : s) {
        if (move == 'D') {
            // Leaving row r, so fix row r
            long long val = -row_sum[r];
            a[r][c] = val;
            row_sum[r] += val;
            col_sum[c] += val;
            r++;
        } else {
            // Leaving col c, so fix col c
            long long val = -col_sum[c];
            a[r][c] = val;
            col_sum[c] += val;
            row_sum[r] += val;
            c++;
        }
    }
    // Last cell (n-1, m-1)
    // Fix last row (or last col)
    long long val = -row_sum[n - 1];
    a[n - 1][m - 1] = val;
    row_sum[n - 1] += val;
    col_sum[m - 1] += val;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
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

