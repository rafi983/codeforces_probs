#include <iostream>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;


    if (y <= x + 1 && (x - y + 1) % 9 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

