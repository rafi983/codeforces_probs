#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // Compute suffix sums for cnt
    for (int i = n; i >= 1; --i) {
        cnt[i] += cnt[i + 1];
    }

    long long ans = 0;
    for (int L = 1; L < n; ++L) {
        int R = n - L;
        // Number of paints that can cover Left part
        long long countL = cnt[L];
        // Number of paints that can cover Right part
        long long countR = cnt[R];

        long long overlap = cnt[max(L, R)];

        ans += (countL * countR - overlap);
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

