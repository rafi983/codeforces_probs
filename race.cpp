#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int a, x, y;
    if (!(cin >> a >> x >> y)) return;

    int dist_ax = abs(a - x);
    int dist_ay = abs(a - y);

    for (int b = -200; b <= 400; ++b) {
        if (b == a) continue;
        if (abs(b - x) < dist_ax && abs(b - y) < dist_ay) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
