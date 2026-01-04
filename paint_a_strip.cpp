#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    int cur = 1;
    int ops = 1;
    while (cur < n) {
        cur = cur * 2 + 2;
        ops++;
    }
    cout << ops << endl;
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

