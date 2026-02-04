#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    if (n == 1) {
        cout << "1\n1\n";
        return;
    }

    if (k == 1 || k == n) {
        cout << "-1\n";
        return;
    }

    int x = ((k - 1) % 2 != 0) ? 1 : 2;

    cout << (2 * x + 1) << "\n";
    for (int i = 1; i <= x; ++i) {
        cout << i << " ";
    }
    cout << k << " ";
    for (int i = 1; i <= x; ++i) {
        cout << (k + i) << (i == x ? "" : " ");
    }
    cout << "\n";
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
