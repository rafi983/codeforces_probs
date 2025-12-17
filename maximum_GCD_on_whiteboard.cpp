#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> P(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        P[i] = P[i - 1] + cnt[i];
    }

    for (int g = n; g >= 1; --g) {
        int limit = min(n, 4 * g - 1);
        int bad = P[limit]; // count of numbers in [1, limit]

        // Subtract multiples of g in [1, limit]
        // Multiples are g, 2g, 3g
        if (g <= limit) bad -= cnt[g];
        if (2 * g <= limit) bad -= cnt[2 * g];
        if (3 * g <= limit) bad -= cnt[3 * g];

        if (bad <= k) {
            cout << g << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
