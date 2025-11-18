#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long freqK = 0;
        int presentBelow = 0;
        if (k > 0) {
            vector<char> seen(k, 0);
            for (int x : a) {
                if (x == k) ++freqK;
                if (0 <= x && x < k && !seen[x]) {
                    seen[x] = 1;
                    ++presentBelow;
                }
            }
        } else {
            for (int x : a) if (x == k) ++freqK; // k == 0 case
        }
        int missingBelow = k - presentBelow;
        long long ops = max<long long>(missingBelow, freqK);
        cout << ops << '\n';
    }
    return 0;
}

