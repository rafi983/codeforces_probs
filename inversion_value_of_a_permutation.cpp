#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int dp[31][450]; // dp[i][j] stores the length of the last block used to achieve sum of lengths i and cost j. -1 if impossible.

void precompute() {
    for (int i = 0; i <= 30; ++i) {
        for (int j = 0; j < 450; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 450; ++j) {
            if (dp[i][j] != -1) {
                for (int len = 1; i + len <= 30; ++len) {
                    int cost = len * (len - 1) / 2;
                    if (j + cost < 450) {
                        dp[i + len][j + cost] = len;
                    }
                }
            }
        }
    }
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    int max_inv = n * (n - 1) / 2;
    int target = max_inv - k;

    if (target < 0 || dp[n][target] == -1) {
        cout << 0 << endl;
        return;
    }

    vector<int> lengths;
    int curr_n = n;
    int curr_target = target;
    while (curr_n > 0) {
        int len = dp[curr_n][curr_target];
        lengths.push_back(len);
        curr_n -= len;
        curr_target -= len * (len - 1) / 2;
    }

    vector<int> result;
    int current_val = n;
    for (int len : lengths) {
        // We assign values current_val - len + 1 to current_val
        // in increasing order
        for (int i = 0; i < len; ++i) {
            result.push_back(current_val - len + 1 + i);
        }
        current_val -= len;
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

