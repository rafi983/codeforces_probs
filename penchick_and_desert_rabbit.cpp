#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) return;

    vector<int> P(n);
    P[0] = a[0];
    for (int i = 1; i < n; ++i) {
        P[i] = max(P[i-1], a[i]);
    }

    vector<int> S(n);
    S[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; --i) {
        S[i] = min(S[i+1], a[i]);
    }

    vector<int> ans(n);
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (P[i] <= S[i+1]) {
            int max_val = 0;
            for(int k=start; k<=i; ++k) max_val = max(max_val, a[k]);
            for(int k=start; k<=i; ++k) ans[k] = max_val;
            start = i + 1;
        }
    }

    int max_val = 0;
    for(int k=start; k<n; ++k) max_val = max(max_val, a[k]);
    for(int k=start; k<n; ++k) ans[k] = max_val;

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n-1 ? "" : " ");
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
