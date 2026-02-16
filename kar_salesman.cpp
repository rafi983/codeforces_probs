#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    long long max_val = 0;
    long long sum_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
        sum_val += a[i];
    }

    long long ans = max(max_val, (sum_val + x - 1) / x);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

