#include <iostream>

using namespace std;

void solve() {
    int x;
    if (!(cin >> x)) return;

    int k = -1;
    for (int i = 29; i >= 0; --i) {
        if ((x >> i) & 1) {
            k = i;
            break;
        }
    }

    int m = -1;
    for (int i = k - 1; i >= 0; --i) {
        if ((x >> i) & 1) {
            m = i;
            break;
        }
    }

    if (m == -1) {
        cout << -1 << "\n";
        return;
    }

    // Check for p < m
    for (int p = 0; p < m; ++p) {
        if (!((x >> p) & 1)) {
            int y = (1 << k) | (1 << p);
            cout << y << "\n";
            return;
        }
    }

    // Check for m < p < k
    for (int p = m + 1; p < k; ++p) {
        if (!((x >> p) & 1)) {
            int y = (1 << p) | (1 << m);
            cout << y << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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
