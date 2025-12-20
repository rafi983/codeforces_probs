#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            cout << -1 << " ";
        } else {
            if (i == n) {
                cout << 2 << " ";
            } else {
                cout << 3 << " ";
            }
        }
    }
    cout << "\n";
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

