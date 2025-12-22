#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

struct Rect {
    int l, b;
};

void solve() {
    vector<Rect> r(3);
    long long area = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> r[i].l >> r[i].b;
        area += (long long)r[i].l * r[i].b;
    }

    long long s = round(sqrt(area));
    if (s * s != area) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (r[i].l > s || r[i].b > s) {
            cout << "NO\n";
            return;
        }
    }

    // Case 1: 3 vertical strips (all have height s)
    if (r[0].b == s && r[1].b == s && r[2].b == s) {
        if (r[0].l + r[1].l + r[2].l == s) {
            cout << "YES\n";
            return;
        }
    }

    // Case 2: 3 horizontal strips (all have width s)
    if (r[0].l == s && r[1].l == s && r[2].l == s) {
        if (r[0].b + r[1].b + r[2].b == s) {
            cout << "YES\n";
            return;
        }
    }

    // Case 3: One splits, two others fill remaining
    for (int i = 0; i < 3; ++i) {
        // Try rectangle i as the full-width one (l = s)
        if (r[i].l == s) {
            int rem_b = s - r[i].b;
            if (rem_b > 0) {
                // The other two must have height rem_b and sum of lengths s
                int j = (i + 1) % 3;
                int k = (i + 2) % 3;
                if (r[j].b == rem_b && r[k].b == rem_b && r[j].l + r[k].l == s) {
                    cout << "YES\n";
                    return;
                }
            }
        }

        // Try rectangle i as the full-height one (b = s)
        if (r[i].b == s) {
            int rem_l = s - r[i].l;
            if (rem_l > 0) {
                // The other two must have length rem_l and sum of heights s
                int j = (i + 1) % 3;
                int k = (i + 2) % 3;
                if (r[j].l == rem_l && r[k].l == rem_l && r[j].b + r[k].b == s) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";
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

