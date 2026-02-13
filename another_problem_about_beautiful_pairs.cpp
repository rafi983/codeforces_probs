#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;
    int S = sqrt(n);

    for (int x = 1; x <= S; ++x) {
        for (int j = 0; j < n; ++j) {
            long long i_idx = (long long)j - (long long)x * a[j];

            if (i_idx >= 0) {
                if (a[i_idx] == x) {
                    ans++;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] > S) {
            for (long long y = 1; ; ++y) {
                long long j_idx = i + (long long)a[i] * y;
                if (j_idx >= n) break; // Out of bounds

                if (a[j_idx] == y) {
                    ans++;
                }
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

