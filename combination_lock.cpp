#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    if (n % 2 == 0) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << ((2 * i) % n) + 1 << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

