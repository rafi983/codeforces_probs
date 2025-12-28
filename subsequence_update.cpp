#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, l, r;
    if (!(cin >> n >> l >> r)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Adjust to 0-based indexing
    int l_idx = l - 1;
    int r_idx = r - 1;
    int len = r - l + 1;

    vector<long long> left_part;
    for (int i = 0; i <= r_idx; ++i) {
        left_part.push_back(a[i]);
    }
    sort(left_part.begin(), left_part.end());
    long long sum1 = 0;
    for (int i = 0; i < len; ++i) {
        sum1 += left_part[i];
    }

    vector<long long> right_part;
    for (int i = l_idx; i < n; ++i) {
        right_part.push_back(a[i]);
    }
    sort(right_part.begin(), right_part.end());
    long long sum2 = 0;
    for (int i = 0; i < len; ++i) {
        sum2 += right_part[i];
    }

    cout << min(sum1, sum2) << endl;
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
