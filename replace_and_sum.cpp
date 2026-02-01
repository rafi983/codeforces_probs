#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        m[i] = max(a[i], b[i]);
    }

    vector<int> s(n);
    int current_max = 0;
    for (int i = n - 1; i >= 0; --i) {
        current_max = max(current_max, m[i]);
        s[i] = current_max;
    }

    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + s[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        long long sum = p[r + 1] - p[l];
        cout << sum << (i == q - 1 ? "" : " ");
    }
    cout << "\n";
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
