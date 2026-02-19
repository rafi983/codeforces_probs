#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(2, false));
    dp[1][0] = true; // Player 1, match 0 nonexistent (win=0)

    for (int i = 1; i < n; ++i) { // processing player i (1-based index)
        for (int pw = 0; pw <= 1; ++pw) {
            if (!dp[i][pw]) continue;

            for (int cw = 0; cw <= 1; ++cw) {
                int wins = pw + cw;
                bool ok = false;
                if (a[i-1] == 0) { // Player i reported 0
                    if (wins == 0) ok = true;
                } else { // Player i reported 1
                    if (wins > 0) ok = true;
                }

                if (ok) {
                    int next_pw = 1 - cw;
                    dp[i+1][next_pw] = true;
                }
            }
        }
    }

    // Check player n
    bool possible = false;
    for (int pw = 0; pw <= 1; ++pw) {
        if (dp[n][pw]) {
            int wins = pw; // Player n has no next match
            bool ok = false;
            if (a[n-1] == 0) {
                if (wins == 0) ok = true;
            } else {
                if (wins > 0) ok = true;
            }
            if (ok) possible = true;
        }
    }

    if (possible) cout << "NO" << endl;
    else cout << "YES" << endl;
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

