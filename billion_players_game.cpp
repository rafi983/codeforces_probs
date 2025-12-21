#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    long long l, r;
    cin >> n >> l >> r;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long X_base = 0;
    long long Y_base = 0;
    vector<long long> b;

    for (long long val : a) {
        if (val < l) {
            X_base += (l - val);
            Y_base += (r - val);
        } else if (val > r) {
            X_base += (val - l);
            Y_base += (val - r);
        } else {
            b.push_back(val);
        }
    }

    long long delta_base = Y_base - X_base;
    long long D = r - l;

    vector<long long> w;
    long long current_w_sum = 0;

    for (long long val : b) {
        long long w_val = 2 * val - (l + r);
        w.push_back(w_val);
        w.push_back(w_val);
        current_w_sum += (-w_val);
    }

    sort(w.rbegin(), w.rend());

    long long m = b.size();
    long long max_obj = -4e18; // Initialize with a very small number

    // K ranges from -m to m
    // t ranges from 0 to 2m
    // K = -m + t

    for (int t = 0; t <= 2 * m; ++t) {
        long long K = -m + t;
        long long obj = current_w_sum - abs(delta_base - D * K);
        if (obj > max_obj) {
            max_obj = obj;
        }

        if (t < 2 * m) {
            current_w_sum += w[t];
        }
    }

    long long ans = (X_base + Y_base + max_obj) / 2;
    cout << ans << "\n";
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

