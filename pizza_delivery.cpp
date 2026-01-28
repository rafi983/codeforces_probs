#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;

ll calc(ll entry, ll exit, ll L, ll R) {
    if (exit == L) {
        if (entry > R) return entry - L;
        return 2 * R - L - entry;
    } else {
        if (entry < L) return R - entry;
        return entry + R - 2 * L;
    }
}

void solve() {
    int n;
    ll Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    map<int, pair<ll, ll>> cols;
    for (int i = 0; i < n; i++) {
        if (!cols.count(x[i])) {
            cols[x[i]] = {y[i], y[i]};
        } else {
            cols[x[i]].first = min(cols[x[i]].first, y[i]);
            cols[x[i]].second = max(cols[x[i]].second, y[i]);
        }
    }

    cols[Bx] = {By, By}; // Add destination

    ll dpL = 0, dpR = 0;
    ll prevL = Ay, prevR = Ay; // Start point

    for (auto const& [currX, interval] : cols) {
        ll L = interval.first;
        ll R = interval.second;

        // Cost to end at L of current column
        ll fromL_toL = dpL + calc(prevL, L, L, R);
        ll fromR_toL = dpR + calc(prevR, L, L, R);
        ll next_dpL = min(fromL_toL, fromR_toL);

        // Cost to end at R of current column
        ll fromL_toR = dpL + calc(prevL, R, L, R);
        ll fromR_toR = dpR + calc(prevR, R, L, R);
        ll next_dpR = min(fromL_toR, fromR_toR);

        dpL = next_dpL;
        dpR = next_dpR;
        prevL = L;
        prevR = R;
    }

    cout << min(dpL, dpR) + (Bx - Ax) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
