#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    if (y < x) {
        cout << x << endl;
    } else {
        if (x + k >= y) {
            cout << y << endl;
        } else {
            cout << 2 * y - x - k << endl;
        }
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

