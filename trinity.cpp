#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int max_len = 0;


    for (int i = 0; i < n - 1; ++i) {
        if (n - i <= max_len) break;

        long long sum = (long long)a[i] + a[i+1];

        auto it = lower_bound(a.begin() + i + 2, a.end(), sum);

        int current_len = distance(a.begin() + i, it);
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    cout << n - max_len << "\n";
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
