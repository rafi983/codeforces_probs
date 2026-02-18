#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> maxLen(n + 1, 0); // max contiguous segment length per value (values are in [1, n])
        int cur = a[0], len = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == cur) {
                ++len;
            } else {
                maxLen[cur] = max(maxLen[cur], len);
                cur = a[i];
                len = 1;
            }
        }
        maxLen[cur] = max(maxLen[cur], len);

        long long ans = LLONG_MAX;
        for (int val = 1; val <= n; ++val) {
            if (maxLen[val] == 0) continue; // value not present
            long long cost = 1LL * val * (n - maxLen[val]);
            ans = min(ans, cost);
        }

        cout << ans << '\n';
    }
    return 0;
}
