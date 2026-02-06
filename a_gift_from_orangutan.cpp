#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = 1001;
    int max_val = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    long long ans = (long long)(n - 1) * (max_val - min_val);
    cout << ans << endl;
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
