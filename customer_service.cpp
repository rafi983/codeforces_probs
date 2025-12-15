#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        int count = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (a[j] == 1) {
                count++;
            } else {
                break;
            }
        }
        l[i] = count;
    }

    sort(l.begin(), l.end(), greater<int>());

    int ans = 0;
    int min_val = 2e9;
    for (int k = 1; k <= n; ++k) {
        min_val = min(min_val, l[k - 1] + k);
        if (min_val >= k) {
            ans = k;
        } else {
            break;
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
