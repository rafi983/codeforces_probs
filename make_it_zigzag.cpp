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

    vector<long long> P(n);
    long long current_max = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] > current_max) {
            current_max = a[i];
        }
        P[i] = current_max;
    }

    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
        // i is 0-based index, so it corresponds to 1st, 3rd, 5th... (odd positions in 1-based)
        // We want a[i] < P[neighbor]

        long long limit = 2e18; // Initialize with a large value
        bool has_neighbor = false;

        if (i > 0) {
            limit = min(limit, P[i - 1]);
            has_neighbor = true;
        }
        if (i + 1 < n) {
            limit = min(limit, P[i + 1]);
            has_neighbor = true;
        }

        if (!has_neighbor) continue;

        // We need a[i] < limit
        // So a[i] <= limit - 1
        if (a[i] >= limit) {
            ans += (a[i] - (limit - 1));
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
