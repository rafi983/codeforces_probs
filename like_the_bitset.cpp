#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;

    vector<int> zeros;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            zeros.push_back(i + 1);
        }
    }

    vector<int> P;
    int curr = 0;
    bool possible = true;

    while (curr + k < n + 1) {
        auto it = upper_bound(zeros.begin(), zeros.end(), curr + k);

        if (it == zeros.begin()) {
            possible = false;
            break;
        }

        --it;
        int next_pos = *it;

        if (next_pos <= curr) {
            possible = false;
            break;
        }

        P.push_back(next_pos);
        curr = next_pos;
    }

    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> ans(n + 1);
        vector<bool> in_P(n + 1, false);

        for (int x : P) in_P[x] = true;

        int large_val = n;
        int small_val = 1;

        for (int i = 1; i <= n; ++i) {
            if (in_P[i]) {
                ans[i] = large_val--;
            } else {
                ans[i] = small_val++;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << (i == n ? "" : " ");
        }
        cout << endl;
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

