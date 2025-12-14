#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (a[i] > 0 ? a[i] : 0);
    }

    vector<long long> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + (a[i] < 0 ? -a[i] : 0);
    }

    long long max_coins = 0;
    for (int k = 0; k <= n; ++k) {
        max_coins = max(max_coins, pref[k] + suff[k]);
    }

    cout << max_coins << endl;
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

