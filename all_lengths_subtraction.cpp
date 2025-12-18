#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<bool> available(n + 1, true); // 1-based lengths

    for (int i = 0; i < n; ++i) {
        int needed = p[i];

        // 1. Process mandatory
        // Length L is mandatory if n - L == i => L = n - i
        int mand_L = n - i;
        if (mand_L >= 1 && mand_L <= n && available[mand_L]) {
            // Check validity
            bool ok = true;
            for (int k = 0; k < mand_L; ++k) {
                if (i + k >= n || p[i + k] <= 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok) {
                cout << "NO" << endl;
                return;
            }

            // Apply
            for (int k = 0; k < mand_L; ++k) {
                p[i + k]--;
            }
            available[mand_L] = false;
            needed--;
        }

        if (needed < 0) {
            cout << "NO" << endl;
            return;
        }
        if (needed == 0) continue;

        // 2. Fill remaining with largest valid
        // Collect candidates
        vector<int> candidates;
        for (int L = n; L >= 1; --L) {
            if (available[L]) {
                candidates.push_back(L);
            }
        }

        for (int L : candidates) {
            if (needed == 0) break;

            // Check validity
            if (i + L > n) continue;

            bool ok = true;
            for (int k = 0; k < L; ++k) {
                if (p[i + k] <= 0) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                // Apply
                for (int k = 0; k < L; ++k) {
                    p[i + k]--;
                }
                available[L] = false;
                needed--;
            }
        }

        if (needed > 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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

