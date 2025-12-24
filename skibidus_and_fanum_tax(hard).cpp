#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(b.begin(), b.end());

    long long current_val = -2e18; // Start with a very small number

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        long long best_val = 2e18; // Initialize with a very large number
        bool found = false;

        // Option 1: Keep a[i]
        if (a[i] >= current_val) {
            best_val = min(best_val, a[i]);
            found = true;
        }

        // Option 2: Replace with b[j] - a[i]
        auto it = lower_bound(b.begin(), b.end(), current_val + a[i]);
        if (it != b.end()) {
            long long val = *it - a[i];
            best_val = min(best_val, val);
            found = true;
        }

        if (!found) {
            possible = false;
            break;
        }
        current_val = best_val;
    }

    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
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

