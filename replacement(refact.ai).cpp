#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s, r;
    cin >> s >> r;

    int n0 = 0, n1 = 0;
    for (char c : s) {
        if (c == '0') n0++;
        else n1++;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (n0 == 0 || n1 == 0) {
            cout << "NO" << endl;
            return;
        }
        if (r[i] == '0') {
            n1--;
        } else {
            n0--;
        }
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

