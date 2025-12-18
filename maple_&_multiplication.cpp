#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;

    if (a == b) {
        cout << 0 << endl;
    } else if (a % b == 0 || b % a == 0) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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

