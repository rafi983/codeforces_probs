#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    long long current_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) { // Odd index (1-based) -> +
            current_val += a[i];
        } else { // Even index -> -
            current_val -= a[i];
        }
    }

    long long max_val = current_val;

    int first_odd = -1, last_odd = -1;
    int first_even = -1, last_even = -1;

    for(int i=0; i<n; ++i) {
        if ((i+1)%2 != 0) {
            if (first_odd == -1) first_odd = i;
            last_odd = i;
        } else {
            if (first_even == -1) first_even = i;
            last_even = i;
        }
    }

    if (first_odd != -1 && last_odd != -1 && first_odd != last_odd) {
        max_val = max(max_val, current_val + (last_odd - first_odd)); // indices are 0-based, diff is same as 1-based
    }
    if (first_even != -1 && last_even != -1 && first_even != last_even) {
        max_val = max(max_val, current_val + (last_even - first_even));
    }


    long long min_val_l = 2e18; // Infinity
    bool found_l = false;

    for (int i = 0; i < n; ++i) {
        long long val = 2 * a[i] + (i + 1);
        if ((i + 1) % 2 != 0) { // l is odd (1-based)
            min_val_l = min(min_val_l, val);
            found_l = true;
        } else { // r is even (1-based)
            if (found_l) {
                max_val = max(max_val, current_val + val - min_val_l);
            }
        }
    }


    long long max_val_l = -2e18; // -Infinity
    found_l = false;

    for (int i = 0; i < n; ++i) {
        long long val = 2 * a[i] - (i + 1);
        if ((i + 1) % 2 == 0) { // l is even (1-based)
            max_val_l = max(max_val_l, val);
            found_l = true;
        } else { // r is odd (1-based)
            if (found_l) {
                max_val = max(max_val, current_val + max_val_l - val);
            }
        }
    }

    cout << max_val << endl;
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

