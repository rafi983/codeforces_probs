#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;


    {
        int k = n - 1;
        int rhs = a[n - 1] - a[1];
        int idx = upper_bound(a.begin(), a.end(), rhs) - a.begin();

        for (int j = 1; j < k; ++j) {

            rhs = a[n - 1] - a[j];
            while (idx > 0 && a[idx - 1] > rhs) {
                idx--;
            }

            // Valid i are in [idx, j-1]
            if (idx < j) {
                ans += (j - idx);
            }
        }
    }


    for (int k = 2; k < n - 1; ++k) {
        // Initialize idx for j = 1
        int val1 = a[k] - a[1];
        int val2 = a[n - 1] - a[1] - a[k];
        int rhs = max(val1, val2);
        int idx = upper_bound(a.begin(), a.end(), rhs) - a.begin();

        for (int j = 1; j < k; ++j) {
            val1 = a[k] - a[j];
            val2 = a[n - 1] - a[j] - a[k];
            rhs = max(val1, val2);

            while (idx > 0 && a[idx - 1] > rhs) {
                idx--;
            }

            if (idx < j) {
                ans += (j - idx);
            }
        }
    }

    cout << ans << "\n";
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

