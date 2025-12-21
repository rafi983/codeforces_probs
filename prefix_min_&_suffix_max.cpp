#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pref_min(n);
    pref_min[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref_min[i] = min(pref_min[i - 1], a[i]);
    }

    vector<int> suff_max(n);
    suff_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suff_max[i] = max(suff_max[i + 1], a[i]);
    }

    string result = "";
    for (int i = 0; i < n; ++i) {
        bool possible = false;

        int min_L = (i > 0) ? pref_min[i - 1] : INF;
        if (a[i] < min_L) possible = true;

        int max_R = (i < n - 1) ? suff_max[i + 1] : -INF;
        if (a[i] > max_R) possible = true;

        result += (possible ? '1' : '0');
    }
    cout << result << endl;
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

