#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_sum += abs(a[i] - a[i+1]);
    }

    long long min_sum = total_sum;

    if (n > 1) {
        long long current_sum = total_sum - abs(a[0] - a[1]);
        if (current_sum < min_sum) min_sum = current_sum;
    }

    if (n > 1) {
        long long current_sum = total_sum - abs(a[n-2] - a[n-1]);
        if (current_sum < min_sum) min_sum = current_sum;
    }

    for (int i = 1; i < n - 1; ++i) {
        long long current_sum = total_sum - abs(a[i-1] - a[i]) - abs(a[i] - a[i+1]) + abs(a[i-1] - a[i+1]);
        if (current_sum < min_sum) min_sum = current_sum;
    }

    cout << min_sum << "\n";
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
