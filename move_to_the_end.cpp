#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<long long> preMax(n);
    preMax[0] = a[0];
    for(int i=1; i<n; ++i) preMax[i] = max(preMax[i-1], a[i]);


    for (int k = 1; k <= n; ++k) {
        long long current_k_sum = pref[n] - pref[n - k]; // This is sum of a[n-k...n-1]
        long long ans = current_k_sum;

        if (n - k - 1 >= 0) {
            long long max_outside = preMax[n - k - 1];
            long long option1 = current_k_sum - a[n-k] + max_outside;
            ans = max(ans, option1);
        }

        cout << ans << (k == n ? "" : " ");
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

