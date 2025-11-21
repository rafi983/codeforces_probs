#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;

        vector<int> a(n + 1);
        int mx = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        if (k == 1) {
            cout << (a[j] == mx ? "YES" : "NO") << '\n';
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}

