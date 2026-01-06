#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long max_sum = 0;
    int max_min_val = INT_MIN;

    for (int i = 0; i < n; ++i) {
        max_sum += max(a[i], b[i]);
        max_min_val = max(max_min_val, min(a[i], b[i]));
    }

    cout << max_sum + max_min_val << endl;
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

