#include <iostream>

using namespace std;

bool check(int x, int y) {
    if (x > 2 * y + 2) return false;
    if (y > 2 * x + 2) return false;
    return true;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (check(a, b) && check(c - a, d - b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

