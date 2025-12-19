#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string L, R;
int n;
int memo[12][2][2];

int dp(int idx, bool tightL, bool tightR) {
    if (idx == n) return 0;
    if (memo[idx][tightL][tightR] != -1) return memo[idx][tightL][tightR];

    int lb = tightL ? (L[idx] - '0') : 0;
    int ub = tightR ? (R[idx] - '0') : 9;

    int res = 1e9;

    for (int d = lb; d <= ub; ++d) {
        int cost = 0;
        if (d == (L[idx] - '0')) cost++;
        if (d == (R[idx] - '0')) cost++;

        bool newTightL = tightL && (d == lb);
        bool newTightR = tightR && (d == ub);

        res = min(res, cost + dp(idx + 1, newTightL, newTightR));
    }
    return memo[idx][tightL][tightR] = res;
}

void solve() {
    if (!(cin >> L >> R)) return;
    n = L.length();
    // Reset memo
    for(int i=0; i<n; ++i)
        for(int j=0; j<2; ++j)
            for(int k=0; k<2; ++k)
                memo[i][j][k] = -1;

    cout << dp(0, true, true) << "\n";
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
