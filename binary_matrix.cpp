#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int n_odd = 0;
    for (int i = 0; i < n; ++i) {
        int row_xor = 0;
        for (char c : a[i]) {
            row_xor ^= (c - '0');
        }
        if (row_xor) n_odd++;
    }

    int m_odd = 0;
    for (int j = 0; j < m; ++j) {
        int col_xor = 0;
        for (int i = 0; i < n; ++i) {
            col_xor ^= (a[i][j] - '0');
        }
        if (col_xor) m_odd++;
    }

    cout << max(n_odd, m_odd) << endl;
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

