#include <iostream>

using namespace std;

void solve() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if (l == r && r == d && d == u) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

