#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m, r1, c1, r2, c2;
    if (!(cin >> n >> m >> r1 >> c1 >> r2 >> c2)) return;

    if ((n * m) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    if ((r1 + c1) % 2 == (r2 + c2) % 2) {
        cout << "NO" << endl;
        return;
    }

    if (n == 1) {
        if (c1 > c2) swap(c1, c2);
        // Segments: [1, c1-1], [c1+1, c2-1], [c2+1, m]
        // Lengths: c1-1, c2-c1-1, m-c2
        // All must be even.
        if ((c1 - 1) % 2 == 0 && (c2 - c1 - 1) % 2 == 0 && (m - c2) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    if (m == 1) {
        if (r1 > r2) swap(r1, r2);
        if ((r1 - 1) % 2 == 0 && (r2 - r1 - 1) % 2 == 0 && (n - r2) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    cout << "YES" << endl;
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

