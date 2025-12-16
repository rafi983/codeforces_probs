#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> L(m + 1);
    L[0] = -1;

    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        while (ptr < n && a[ptr] < b[i]) {
            ptr++;
        }
        if (ptr < n) {
            L[i + 1] = ptr;
            ptr++;
        } else {
            for (int k = i + 1; k <= m; ++k) L[k] = INF;
            break;
        }
    }

    if (L[m] != INF) {
        cout << 0 << "\n";
        return;
    }

    vector<int> R(m + 2);
    R[m + 1] = n;

    ptr = n - 1;
    for (int i = m; i >= 1; --i) {
        while (ptr >= 0 && a[ptr] < b[i - 1]) {
            ptr--;
        }
        if (ptr >= 0) {
            R[i] = ptr;
            ptr--;
        } else {
            for (int k = i; k >= 1; --k) R[k] = -INF;
            break;
        }
    }

    int min_k = -1;

    for (int i = 1; i <= m; ++i) {


        if (L[i - 1] == INF) continue;
        if (R[i + 1] == -INF) continue;

        if (L[i - 1] < R[i + 1]) {
            if (min_k == -1 || b[i - 1] < min_k) {
                min_k = b[i - 1];
            }
        }
    }

    cout << min_k << "\n";
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
