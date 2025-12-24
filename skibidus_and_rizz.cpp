#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    if (abs(n - m) > k || k > max(n, m)) {
        cout << "-1" << endl;
        return;
    }

    string s;
    s.reserve(n + m);

    if (n >= m) {
        for (int i = 0; i < k; ++i) s += '0';
        int rem_n = n - k;
        for (int i = 0; i < rem_n; ++i) s += "10";
        int rem_m = m - rem_n;
        for (int i = 0; i < rem_m; ++i) s += '1';
    } else {
        for (int i = 0; i < k; ++i) s += '1';
        int rem_m = m - k;
        for (int i = 0; i < rem_m; ++i) s += "01";
        int rem_n = n - rem_m;
        for (int i = 0; i < rem_n; ++i) s += '0';
    }
    cout << s << endl;
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

