#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    int k;
    if (!(cin >> n >> k)) return;

    vector<long long> l(n);
    vector<long long> r(n);

    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> r[i];

    long long current_sum = 0;
    vector<long long> min_vals;
    min_vals.reserve(n);

    for (int i = 0; i < n; ++i) {
        current_sum += max(l[i], r[i]);
        min_vals.push_back(min(l[i], r[i]));
    }

    sort(min_vals.rbegin(), min_vals.rend());

    for (int i = 0; i < k - 1; ++i) {
        current_sum += min_vals[i];
    }

    cout << current_sum + 1 << "\n";
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
