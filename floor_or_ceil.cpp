#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll solve_min(ll x, ll n, ll m) {
    // Apply Ceil first (m times), then Floor (n times)
    // Ceil
    while (m > 0 && x > 1) {
        x = (x + 1) / 2;
        m--;
    }
    // If x is 1, Ceil keeps it 1. So we don't need to use more m.

    // Floor
    while (n > 0 && x > 0) {
        x = x / 2;
        n--;
    }
    return x;
}

ll solve_max(ll x, ll n, ll m) {
    // Apply Floor first (n times), then Ceil (m times)
    // Floor
    while (n > 0 && x > 0) {
        x = x / 2;
        n--;
    }

    // Ceil
    while (m > 0 && x > 1) {
        x = (x + 1) / 2;
        m--;
    }

    return x;
}

void solve() {
    ll x, n, m;
    if (!(cin >> x >> n >> m)) return;
    cout << solve_min(x, n, m) << " " << solve_max(x, n, m) << endl;
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

