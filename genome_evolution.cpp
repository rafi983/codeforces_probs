#include <iostream>

using namespace std;

void solve() {
    long long a, b, t;
    if (!(cin >> a >> b >> t)) return;

    if (t == 1) {
        cout << a << endl;
    } else if (t == 2) {
        cout << b << endl;
    } else {
        cout << (a & b) << endl;
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
