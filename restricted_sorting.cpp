#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zaman() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    int mn = 2000000000, mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    bool sorted = true;
    int ans = 2000000000;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            sorted = false;
            int constraint = max(a[i] - mn, mx - a[i]);
            if (constraint < ans) {
                ans = constraint;
            }
        }
    }

    if (sorted) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }
    return 0;
}
