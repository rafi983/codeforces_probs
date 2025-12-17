#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        if (a[0] == 1) cout << 2 << endl;
        else cout << 0 << endl;
        return;
    }

    // Check difference constraint
    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i+1] - a[i]) > 1) {
            cout << 0 << endl;
            return;
        }
    }

    int ans = 0;

    // Try x[0] = 0
    {
        vector<int> x(n);
        x[0] = 0;
        bool possible = true;
        for (int i = 0; i < n - 1; ++i) {
            int d = a[i+1] - a[i] + 1;
            // x[i] + x[i+1] = d
            int next_val = d - x[i];
            if (next_val != 0 && next_val != 1) {
                possible = false;
                break;
            }
            x[i+1] = next_val;
        }

        if (possible) {
            long long sum_prefix = 0;
            for (int i = 0; i < n - 1; ++i) sum_prefix += x[i];
            if (sum_prefix == a[n-1] - 1) {
                ans++;
            }
        }
    }

    // Try x[0] = 1
    {
        vector<int> x(n);
        x[0] = 1;
        bool possible = true;
        for (int i = 0; i < n - 1; ++i) {
            int d = a[i+1] - a[i] + 1;
            // x[i] + x[i+1] = d
            int next_val = d - x[i];
            if (next_val != 0 && next_val != 1) {
                possible = false;
                break;
            }
            x[i+1] = next_val;
        }

        if (possible) {
            long long sum_prefix = 0;
            for (int i = 0; i < n - 1; ++i) sum_prefix += x[i];
            if (sum_prefix == a[n-1] - 1) {
                ans++;
            }
        }
    }

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

