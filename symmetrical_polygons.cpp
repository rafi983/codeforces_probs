#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> leftovers;
    long long S = 0;
    long long pairs_count = 0;

    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        int count = j - i;
        long long val = a[i];

        long long num_pairs = count / 2;
        S += num_pairs * val;
        pairs_count += num_pairs;

        if (count % 2 != 0) {
            leftovers.push_back(val);
        }

        i = j;
    }

    long long ans = 0;
    if (pairs_count >= 2) {
        ans = max(ans, 2 * S);
    }

    sort(leftovers.rbegin(), leftovers.rend());

    if (pairs_count >= 1) {
        // Try 1 leftover
        for (long long u : leftovers) {
            if (u < 2 * S) {
                ans = max(ans, 2 * S + u);
                break;
            }
        }

        // Try 2 leftovers
        for (size_t i = 0; i + 1 < leftovers.size(); ++i) {
            long long u = leftovers[i];
            long long v = leftovers[i+1];
            if (u - v < 2 * S) {
                ans = max(ans, 2 * S + u + v);
                break;
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

