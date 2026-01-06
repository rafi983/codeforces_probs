#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    string a, b, c;
    if (!(cin >> a >> b >> c)) return;
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 && j == 0) continue;

            int k = i + j - 1;

            if (i > 0) {
                int cost = (a[i-1] == c[k]) ? 0 : 1;
                dp[i][j] = min(dp[i][j], dp[i-1][j] + cost);
            }

            if (j > 0) {
                int cost = (b[j-1] == c[k]) ? 0 : 1;
                dp[i][j] = min(dp[i][j], dp[i][j-1] + cost);
            }
        }
    }

    cout << dp[n][m] << endl;
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

