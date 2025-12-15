#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int cost = (a[n - 1] - a[0]) + (a[2 * n - 1] - a[n]);
    cout << cost << endl;

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " " << a[n + i] << endl;
    }
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

