#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[405][405];
long long best[405][405];
int a[405];

void solve() {
    int n;
    if (!(cin >> n)) return;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Reset DP tables
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 0;
            best[i][j] = 0;
        }
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;


            if (len >= 3) {
                for (int k = i + 1; k < j; ++k) {
                    long long current_val = (long long)a[i] * a[k] * a[j];
                    current_val += dp[i + 1][k - 1] + dp[k + 1][j - 1];
                    if (current_val > best[i][j]) {
                        best[i][j] = current_val;
                    }
                }
            }


            dp[i][j] = dp[i + 1][j];


            for (int m = i + 2; m <= j; ++m) {
                if (best[i][m] > 0) {
                    long long val = best[i][m] + dp[m + 1][j];
                    if (val > dp[i][j]) {
                        dp[i][j] = val;
                    }
                }
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
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
