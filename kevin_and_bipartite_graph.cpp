#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (m > 2 * n - 1) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < m; ++j) {
            int color;
            if (j < n || i < n) {
                color = (i + j) % n + 1;
            } else {
                color = (i + j + 1) % n + 1;
            }
            cout << color << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

