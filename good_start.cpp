#include <iostream>

using namespace std;

void solve() {
    long long w, h, a, b;
    cin >> w >> h >> a >> b;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    bool ax_aligned = ((x1 % a + a) % a == (x2 % a + a) % a);
    bool ay_aligned = ((y1 % b + b) % b == (y2 % b + b) % b);

    bool disjoint_x = (x1 + a <= x2) || (x2 + a <= x1);
    bool disjoint_y = (y1 + b <= y2) || (y2 + b <= y1);

    if ((ax_aligned && disjoint_x) || (ay_aligned && disjoint_y) || (ax_aligned && ay_aligned)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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