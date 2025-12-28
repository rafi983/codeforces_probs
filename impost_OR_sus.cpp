#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void solve() {
    string r;
    cin >> r;
    int n = r.length();

    for (char c : r) {
        assert(c == 's' || c == 'u');
    }


    const int INF = 1e9;
    int dp0, dp1;

    if (r[0] == 's') {
        dp0 = 0;
    } else {
        dp0 = 1;
    }
    dp1 = INF;

    for (int i = 1; i < n; ++i) {
        int next_dp0, next_dp1;

        int cost_s = (r[i] == 's' ? 0 : 1);
        next_dp0 = min(dp0, dp1) + cost_s;

        if (r[i] == 's') {
            next_dp1 = INF;
        } else {
            int cost_u = 0;
            next_dp1 = dp0 + cost_u;
        }

        dp0 = next_dp0;
        dp1 = next_dp1;
    }

    cout << dp0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
