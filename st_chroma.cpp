#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, x;
    if (!(cin >> n >> x)) return;

    if (x == n) {
        for (int i = 0; i < n; ++i) {
            cout << i << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        for (int i = 0; i < x; ++i) {
            cout << i << " ";
        }
        for (int i = x + 1; i < n; ++i) {
            cout << i << " ";
        }
        cout << x << "\n";
    }
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

