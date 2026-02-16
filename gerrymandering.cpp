#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s[2];
int dp[100005][5];

int check(char a, char b, char c) {
    int cnt = 0;
    if (a == 'A') cnt++;
    if (b == 'A') cnt++;
    if (c == 'A') cnt++;
    return cnt >= 2;
}

void solve() {
    cin >> n;
    cin >> s[0] >> s[1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            dp[i][j] = -1e9;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        if (dp[i][0] != -1e9) {
            if (i + 3 <= n) {
                int val = check(s[0][i], s[0][i+1], s[0][i+2]) + check(s[1][i], s[1][i+1], s[1][i+2]);
                dp[i+3][0] = max(dp[i+3][0], dp[i][0] + val);
            }

            if (i + 2 <= n) {
                int val = check(s[0][i], s[0][i+1], s[1][i]);
                dp[i+1][1] = max(dp[i+1][1], dp[i][0] + val);
            }

            if (i + 2 <= n) {
                int val = check(s[0][i], s[1][i], s[1][i+1]);
                dp[i+1][2] = max(dp[i+1][2], dp[i][0] + val);
            }
        }

        if (dp[i][1] != -1e9) {

            if (i + 2 <= n) {
                int val = check(s[1][i], s[1][i+1], s[0][i+1]);
                dp[i+2][0] = max(dp[i+2][0], dp[i][1] + val);
            }

            if (i + 3 <= n) {
                int val = check(s[1][i], s[1][i+1], s[1][i+2]);
                dp[i+1][4] = max(dp[i+1][4], dp[i][1] + val);
            }
        }

        if (dp[i][2] != -1e9) {
            if (i + 2 <= n) {
                int val = check(s[0][i], s[0][i+1], s[1][i+1]);
                dp[i+2][0] = max(dp[i+2][0], dp[i][2] + val);
            }


            if (i + 3 <= n) {
                int val = check(s[0][i], s[0][i+1], s[0][i+2]);
                dp[i+1][3] = max(dp[i+1][3], dp[i][2] + val);
            }
        }

        if (dp[i][3] != -1e9) {

            if (i + 3 <= n) {
                int val = check(s[1][i], s[1][i+1], s[1][i+2]);
                dp[i+2][2] = max(dp[i+2][2], dp[i][3] + val);
            }
        }

        if (dp[i][4] != -1e9) {

            if (i + 3 <= n) {
                int val = check(s[0][i], s[0][i+1], s[0][i+2]);
                dp[i+2][1] = max(dp[i+2][1], dp[i][4] + val);
            }
        }
    }

    cout << dp[n][0] << "\n";
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
