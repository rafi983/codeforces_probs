#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    vector<int> q(k);
    for (int i = 0; i < k; ++i) cin >> q[i];

    if (k == n) {
        for (int i = 0; i < m; ++i) cout << '1';
        cout << endl;
        return;
    }

    if (k < n - 1) {
        for (int i = 0; i < m; ++i) cout << '0';
        cout << endl;
        return;
    }


    long long total_sum = (long long)n * (n + 1) / 2;
    long long q_sum = 0;
    for (int x : q) q_sum += x;
    int missing_x = total_sum - q_sum;

    for (int i = 0; i < m; ++i) {
        if (a[i] == missing_x) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << endl;
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

