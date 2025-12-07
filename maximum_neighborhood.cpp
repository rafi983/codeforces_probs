#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getValue(ll r, ll c, ll n) {
    return r * n + c + 1;
}

ll getCost(ll r, ll c, ll n) {
    ll cost = getValue(r, c, n);
    // up
    if (r > 0) cost += getValue(r-1, c, n);
    // down
    if (r < n-1) cost += getValue(r+1, c, n);
    // left
    if (c > 0) cost += getValue(r, c-1, n);
    // right
    if (c < n-1) cost += getValue(r, c+1, n);
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll maxCost = 0;
        for (ll r = 0; r < n; r++) {
            for (ll c = 0; c < n; c++) {
                maxCost = max(maxCost, getCost(r, c, n));
            }
        }
        cout << maxCost << "\n";
    }

    return 0;
}
