#include <iostream>

using namespace std;

void solve() {
    long long p, q;
    if (!(cin >> p >> q)) return;

    if (q > p) {
        long long k = q - p;
        if (2 * k <= p) {
            cout << "Bob" << "\n";
        } else {
            cout << "Alice" << "\n";
        }
    } else {
        cout << "Alice" << "\n";
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
