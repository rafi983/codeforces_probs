#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        long long maxK = 0, minK = 0;

        for (int i = 0; i < n; i++) {
            long long newMax = max(maxK - a[i], b[i] - minK);
            long long newMin = min(minK - a[i], b[i] - maxK);
            maxK = newMax;
            minK = newMin;
        }

        cout << maxK << "\n";
    }

    return 0;
}

