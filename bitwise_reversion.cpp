#include <iostream>

using namespace std;

void solve() {
    long long x, y, z;
    if (!(cin >> x >> y >> z)) return;

    bool ok = true;
    if ((x & y) & ~z) ok = false;
    if ((x & z) & ~y) ok = false;
    if ((y & z) & ~x) ok = false;

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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

