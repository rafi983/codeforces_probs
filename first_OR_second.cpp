#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> suffix_sum(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + a[i];
    }

    vector<long long> prefix_abs(n, 0);
    long long current_abs_sum = 0;
    for (int i = 1; i < n; ++i) {
        current_abs_sum += abs(a[i]);
        prefix_abs[i] = current_abs_sum;
    }

    long long max_x = -4e18;

    long long val_0 = -suffix_sum[1];
    max_x = max(max_x, val_0);

    for (int r = 1; r < n; ++r) {

        long long val = a[0] + prefix_abs[r - 1] - suffix_sum[r + 1];
        max_x = max(max_x, val);
    }

    cout << max_x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
