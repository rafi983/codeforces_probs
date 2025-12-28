#include <iostream>

using namespace std;

void solve() {
    long long l, r;
    if (!(cin >> l >> r)) return;

    if (l == r) {
        if (l == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << r - l << endl;
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

