#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    if (!(cin >> n >> s)) return;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int L = x[0];
    int R = x[n - 1];

    int ans = 0;
    if (s <= L) {
        ans = R - s;
    } else if (s >= R) {
        ans = s - L;
    } else {
        ans = (R - L) + min(s - L, R - s);
    }
    cout << ans << "\n";
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

