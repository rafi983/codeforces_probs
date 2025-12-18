#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> s(n);
    // counts[i][c] stores count of char c in s[i]
    vector<vector<int>> counts(n, vector<int>(26, 0));
    vector<int> total_counts(26, 0);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (char c : s[i]) {
            int char_idx = c - 'A';
            counts[i][char_idx]++;
            total_counts[char_idx]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        int max_needed = 0;
        bool possible = true;

        for (int c = 0; c < 26; ++c) {
            int C = counts[i][c];
            int R = total_counts[c] - C;

            if (R == 0) {
                if (C > 0) {
                    possible = false;
                    break;
                }
            } else {

                int needed = (C + R - 1) / R;
                if (needed > max_needed) {
                    max_needed = needed;
                }
            }
        }

        if (!possible) {
            cout << -1 << (i == n - 1 ? "" : " ");
        } else {
            int k = m - max_needed;
            if (k < 0) {
                cout << -1 << (i == n - 1 ? "" : " ");
            } else {
                cout << k << (i == n - 1 ? "" : " ");
            }
        }
    }
    cout << endl;

    return 0;
}

