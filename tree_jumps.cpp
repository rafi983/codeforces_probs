#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> parent(n + 1);
    vector<int> level(n + 1);
    vector<vector<int>> levels(n + 1);

    level[1] = 0;
    levels[0].push_back(1);

    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
        level[i] = level[parent[i]] + 1;
        levels[level[i]].push_back(i);
    }

    vector<long long> dp(n + 1);
    dp[1] = 1;
    long long total_dp_prev = 1;
    long long ans = 1;

    for (int l = 1; l <= n; ++l) {
        if (levels[l].empty()) break;

        long long total_dp_curr = 0;
        for (int u : levels[l]) {
            if (l == 1) {
                dp[u] = 1;
            } else {
                dp[u] = (total_dp_prev - dp[parent[u]] + MOD) % MOD;
            }
            total_dp_curr = (total_dp_curr + dp[u]) % MOD;
        }

        ans = (ans + total_dp_curr) % MOD;
        total_dp_prev = total_dp_curr;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

