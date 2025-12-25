#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcdExtended(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = gcdExtended(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

ll my_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll my_abs(ll a) {
    return a < 0 ? -a : a;
}

void solve() {
    ll n, x, y, vx, vy;
    if (!(cin >> n >> x >> y >> vx >> vy)) return;

    ll cross_prod = vy * x - vx * y;
    if (cross_prod % n != 0) {
        cout << -1 << "\n";
        return;
    }
    ll K = cross_prod / n;

    ll g = my_gcd(vx, vy);
    if (K % g != 0) {
        cout << -1 << "\n";
        return;
    }

    vx /= g;
    vy /= g;
    K /= g;

    ll k;
    if (vx == 1) {
        k = 1;
    } else {
        ll inv = modInverse(vy, vx);
        k = ( (K % vx) * inv ) % vx;
        k = (k + vx) % vx;
        if (k == 0) k = vx;
    }

    ll m = (k * vy - K) / vx;

    ll ans = (k - 1) + (m - 1) + (k + m) / 2 + my_abs(k - m) / 2;
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
