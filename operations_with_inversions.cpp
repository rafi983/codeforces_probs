#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int mx = INT_MIN;
        long long ops = 0;

        for (int i = 0; i < n; ++i) {
            if (mx == INT_MIN) {
                mx = a[i];
                continue;
            }
            if (a[i] < mx) {
                ops++;
            } else {
                mx = a[i];
            }
        }

        cout << ops << "\n";
    }

    return 0;
}
