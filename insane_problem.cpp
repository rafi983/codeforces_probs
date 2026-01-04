#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    long long ans = 0;
    long long p = 1;

    while (p <= r2) {


        long long min_x_y = (l2 + p - 1) / p;
        long long max_x_y = r2 / p;

        long long actual_l = max(l1, min_x_y);
        long long actual_r = min(r1, max_x_y);

        if (actual_l <= actual_r) {
            ans += (actual_r - actual_l + 1);
        }

        if (r2 / k < p) {
            break;
        }
        p *= k;
    }
    cout << ans << endl;
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
