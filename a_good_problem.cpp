#include <iostream>

using namespace std;

void solve() {
    long long n, l, r, k;
    if (!(cin >> n >> l >> r >> k)) return;

    if (n % 2 != 0) {
        cout << l << "\n";
    } else {
        if (n == 2) {
            cout << -1 << "\n";
        } else {
            long long x = 1;
            while (x <= l) {
                x <<= 1;
            }

            if (x <= r) {
                if (k <= n - 2) {
                    cout << l << "\n";
                } else {
                    cout << x << "\n";
                }
            } else {
                cout << -1 << "\n";
            }
        }
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

