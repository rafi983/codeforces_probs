#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

bool is_adjacent(int u, int v) {
    return (u != v) && (u + v != 5);
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> dp(6, INF);

    for (int v = 0; v < 6; ++v) {
        dp[v] = (a[0] == v ? 0 : 1);
    }

    for (int i = 1; i < n; ++i) {
        vector<int> next_dp(6, INF);
        for (int curr_val = 0; curr_val < 6; ++curr_val) {
            int cost = (a[i] == curr_val ? 0 : 1);
            int min_prev = INF;

            for (int prev_val = 0; prev_val < 6; ++prev_val) {
                if (is_adjacent(prev_val, curr_val)) {
                    min_prev = min(min_prev, dp[prev_val]);
                }
            }

            if (min_prev != INF) {
                next_dp[curr_val] = min_prev + cost;
            }
        }
        dp = next_dp;
    }

    int result = INF;
    for (int v = 0; v < 6; ++v) {
        result = min(result, dp[v]);
    }
    cout << result << "\n";
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

