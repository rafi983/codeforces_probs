#include <bits/stdc++.h>
using namespace std;

static inline long long minimax_pair_diff(vector<long long>& a) {
    sort(a.begin(), a.end());
    long long mx = 0;
    for (size_t i = 0; i + 1 < a.size(); i += 2) {
        mx = max(mx, a[i + 1] - a[i]);
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << minimax_pair_diff(a) << '\n';
    }
    return 0;
}

