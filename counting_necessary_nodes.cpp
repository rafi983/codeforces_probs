#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve1D(ll l, ll r, ll width) {
    ll ans = 0;
    ll curr = l;
    while (curr < r) {
        ll h = 1;
        // Largest power of 2 dividing curr
        ll max_h_div = (curr == 0) ? (1LL << 60) : (curr & -curr);

        // Largest power of 2 <= remaining length
        ll rem = r - curr;
        ll max_h_len = 1;
        while ((max_h_len << 1) <= rem) max_h_len <<= 1;

        h = min(max_h_div, max_h_len);

        ans += width / h;
        curr += h;
    }
    return ans;
}

ll solve(ll x, ll y, ll size, ll l1, ll r1, ll l2, ll r2) {
    ll lx = max(x, l1);
    ll rx = min(x + size, r1);
    ll ly = max(y, l2);
    ll ry = min(y + size, r2);

    if (lx >= rx || ly >= ry) return 0;

    bool full_x = (lx == x && rx == x + size);
    bool full_y = (ly == y && ry == y + size);

    if (full_x) {
        return solve1D(ly, ry, size);
    }
    if (full_y) {
        return solve1D(lx, rx, size);
    }

    ll half = size / 2;
    return solve(x, y, half, l1, r1, l2, r2) +
           solve(x + half, y, half, l1, r1, l2, r2) +
           solve(x, y + half, half, l1, r1, l2, r2) +
           solve(x + half, y + half, half, l1, r1, l2, r2);
}

void run_test_case() {
    ll l1, r1, l2, r2;
    if (!(cin >> l1 >> r1 >> l2 >> r2)) return;
    cout << solve(0, 0, 1048576, l1, r1, l2, r2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            run_test_case();
        }
    }
    return 0;
}

