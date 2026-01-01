#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        max_val = max(max_val, intervals[i].second);
    }

    vector<int> count(max_val + 2, 0);

    for (int i = 0; i < n; ++i) {
        if (intervals[i].first == intervals[i].second) {
            count[intervals[i].first]++;
        }
    }

    vector<int> P(max_val + 2, 0);
    for (int i = 1; i <= max_val; ++i) {
        P[i] = P[i-1] + (count[i] > 0 ? 1 : 0);
    }

    string ans = "";
    for (int i = 0; i < n; ++i) {
        int l = intervals[i].first;
        int r = intervals[i].second;

        if (l == r) {
            if (count[l] == 1) {
                ans += '1';
            } else {
                ans += '0';
            }
        } else {
            int fixed_cnt = P[r] - P[l-1];
            int len = r - l + 1;
            if (fixed_cnt == len) {
                ans += '0';
            } else {
                ans += '1';
            }
        }
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

