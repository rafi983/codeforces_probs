#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k_max;
    if (!(cin >> n >> k_max)) return;
    string s, t;
    cin >> s >> t;

    vector<vector<int>> nxt(n + 1, vector<int>(26, -1));
    for (int i = n - 1; i >= 0; --i) {
        for (int c = 0; c < 26; ++c) {
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }

    vector<int> p(n);

    auto check = [&](int k) -> bool {
        int prev_p = -1;
        for (int i = 0; i < n; ++i) {
            int min_idx = max(prev_p, i - k);
            if (min_idx < 0) min_idx = 0;
            if (min_idx >= n) return false; // Should not happen given i-k < n

            int char_idx = t[i] - 'a';
            int found_idx = nxt[min_idx][char_idx];

            if (found_idx == -1 || found_idx > i) {
                return false;
            }
            p[i] = found_idx;
            prev_p = found_idx;
        }
        return true;
    };

    int low = 0, high = k_max, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (ans == -1) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
        check(ans);

        vector<int> v(n);
        for (int i = 0; i < n; ++i) v[i] = i;

        for (int step = 1; step <= ans; ++step) {
            vector<int> next_v(n);
            next_v[0] = v[0]; // s'_1 = s_1 always, so index comes from 0
            for (int i = 1; i < n; ++i) {

                if (v[i - 1] >= p[i]) {
                    next_v[i] = v[i - 1];
                } else {
                    next_v[i] = v[i];
                }
            }
            v = next_v;

            string current_s = "";
            for (int i = 0; i < n; ++i) {
                current_s += s[v[i]];
            }
            cout << current_s << "\n";
        }
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
