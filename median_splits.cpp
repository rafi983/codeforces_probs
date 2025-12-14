#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = (a[i] <= k) ? 1 : -1;
    }

    vector<int> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] + b[i];
    }

    // Precompute Rmax and Rmin
    // Rmax[i] = max(P[i], ..., P[n-1])
    // Rmin[i] = min(P[i], ..., P[n-1])

    vector<int> Rmax(n + 1, -1e9);
    vector<int> Rmin(n + 1, 1e9);

    Rmax[n - 1] = P[n - 1];
    Rmin[n - 1] = P[n - 1];

    for (int i = n - 2; i >= 1; --i) {
        Rmax[i] = max(P[i], Rmax[i + 1]);
        Rmin[i] = min(P[i], Rmin[i + 1]);
    }

    // Precompute Lmin
    // Lmin[i] = min(P[1], ..., P[i])
    vector<int> Lmin(n + 1, 1e9);
    Lmin[1] = P[1];
    for (int i = 2; i < n; ++i) {
        Lmin[i] = min(P[i], Lmin[i - 1]);
    }

    bool possible = false;

    // Condition 1: S1 >= 0 and S2 >= 0
    // exists l in [1, n-2] s.t. P[l] >= 0 and Rmax[l+1] >= P[l]
    for (int l = 1; l <= n - 2; ++l) {
        if (P[l] >= 0) {
            if (Rmax[l + 1] >= P[l]) {
                possible = true;
                break;
            }
        }
    }

    if (!possible) {
        // Condition 2: S1 >= 0 and S3 >= 0
        // exists l in [1, n-2] s.t. P[l] >= 0 and Rmin[l+1] <= P[n]
        for (int l = 1; l <= n - 2; ++l) {
            if (P[l] >= 0) {
                if (Rmin[l + 1] <= P[n]) {
                    possible = true;
                    break;
                }
            }
        }
    }

    if (!possible) {
        // Condition 3: S2 >= 0 and S3 >= 0
        // exists r in [2, n-1] s.t. P[r] <= P[n] and Lmin[r-1] <= P[r]
        for (int r = 2; r <= n - 1; ++r) {
            if (P[r] <= P[n]) {
                if (Lmin[r - 1] <= P[r]) {
                    possible = true;
                    break;
                }
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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

