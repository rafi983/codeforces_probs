#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int x = -1, y = -1;
        for (int i = 0; i < n && x == -1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    x = a[i];
                    y = a[j];
                    break;
                }
            }
        }

        if (x == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << 2 << '\n';
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}
