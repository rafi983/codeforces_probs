#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    long long c4 = 0;
    long long c8 = 0;

    for (char c : s) {
        if (c == '4') {
            c4++;
        } else {
            c8++;
        }
    }

    long long dist_x = max(0LL, abs(x) - c8);
    long long dist_y = max(0LL, abs(y) - c8);

    if (dist_x + dist_y <= c4) {
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

