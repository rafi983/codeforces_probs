#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }

    vector<int> min_h(n + 1), max_h(n + 1);
    min_h[0] = 0;
    max_h[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int range_min, range_max;
        if (d[i] == -1) {
            range_min = min_h[i - 1];
            range_max = max_h[i - 1] + 1;

        } else if (d[i] == 0) {
            range_min = min_h[i - 1];
            range_max = max_h[i - 1];

        } else {
            range_min = min_h[i - 1] + 1;
            range_max = max_h[i - 1] + 1;
        }

        min_h[i] = max(range_min, l[i]);
        max_h[i] = min(range_max, r[i]);

        if (min_h[i] > max_h[i]) {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> ans(n + 1);
    int curr_h = min_h[n];

    for (int i = n; i >= 1; --i) {
        int prev_h;

        if (d[i] != -1) {
            ans[i] = d[i];
            prev_h = curr_h - d[i];
        } else {
            // Try d[i] = 0
            bool valid0 = (curr_h >= min_h[i - 1] && curr_h <= max_h[i - 1]);
            // Try d[i] = 1
            bool valid1 = (curr_h - 1 >= min_h[i - 1] && curr_h - 1 <= max_h[i - 1]);

            if (valid0) {
                ans[i] = 0;
                prev_h = curr_h;
            } else {
                ans[i] = 1;
                prev_h = curr_h - 1;
            }
        }
        curr_h = prev_h;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << endl;
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

