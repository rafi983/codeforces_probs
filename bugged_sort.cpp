#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int min_val;
    int max_val;
    int original_flip; // 0 if a < b, 1 if a > b
    int sum;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<Pair> pairs(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            pairs[i] = {a[i], b[i], 0, a[i] + b[i]};
        } else {
            pairs[i] = {b[i], a[i], 1, a[i] + b[i]};
        }
    }

    sort(pairs.begin(), pairs.end(), [](const Pair& x, const Pair& y) {
        return x.sum < y.sum;
    });

    for (int i = 0; i < n - 1; ++i) {
        if (pairs[i].sum == pairs[i+1].sum) {
            cout << "NO" << endl;
            return;
        }
    }

    int dp[2] = {1, 0}; // Initial state: dummy pair (0,0) with parity 0

    int prev_a[2] = {0, 0};
    int prev_b[2] = {0, 0};

    for (int i = 0; i < n; ++i) {
        int next_dp[2] = {0, 0};
        int curr_vals[2][2]; // [ori][0=a, 1=b]

        curr_vals[0][0] = pairs[i].min_val;
        curr_vals[0][1] = pairs[i].max_val;
        curr_vals[1][0] = pairs[i].max_val;
        curr_vals[1][1] = pairs[i].min_val;

        for (int prev_ori = 0; prev_ori < 2; ++prev_ori) {
            if (dp[prev_ori] == 0) continue;

            // Try transition to curr_ori 0
            if (prev_a[prev_ori] < curr_vals[0][0] && prev_b[prev_ori] < curr_vals[0][1]) {
                int cost = pairs[i].original_flip;
                int mask = dp[prev_ori];
                if (cost) {
                    mask = ((mask & 1) << 1) | ((mask & 2) >> 1);
                }
                next_dp[0] |= mask;
            }

            // Try transition to curr_ori 1
            if (prev_a[prev_ori] < curr_vals[1][0] && prev_b[prev_ori] < curr_vals[1][1]) {
                int cost = 1 - pairs[i].original_flip;
                int mask = dp[prev_ori];
                if (cost) {
                    mask = ((mask & 1) << 1) | ((mask & 2) >> 1);
                }
                next_dp[1] |= mask;
            }
        }

        dp[0] = next_dp[0];
        dp[1] = next_dp[1];
        prev_a[0] = curr_vals[0][0];
        prev_b[0] = curr_vals[0][1];
        prev_a[1] = curr_vals[1][0];
        prev_b[1] = curr_vals[1][1];
    }

    if ((dp[0] & 1) || (dp[1] & 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

