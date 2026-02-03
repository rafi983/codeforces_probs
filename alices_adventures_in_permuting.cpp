#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, b, c;
    if (!(cin >> n >> b >> c)) return;

    if (b == 0) {
        if (c >= n) {
            cout << n << "\n";
        } else if (c >= n - 2) {
            cout << n - 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    } else {
        if (c >= n) {
            cout << n << "\n";
        } else {
            long long valid_count = (n - c - 1) / b + 1;
            cout << n - valid_count << "\n";
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
