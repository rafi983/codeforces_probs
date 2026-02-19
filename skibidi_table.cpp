#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

void find_d(int n, ll x, ll y) {
    ll d = 1;


    for (int k = n; k >= 1; --k) {
        ll mid = (1LL << (k - 1));
        ll S = (1LL << (2 * (k - 1)));

        if (x <= mid && y <= mid) {

        } else if (x > mid && y > mid) {
            d += S;
            x -= mid;
            y -= mid;
        } else if (x > mid && y <= mid) {
            d += 2 * S;
            x -= mid;
        } else {
            d += 3 * S;
            y -= mid;
        }
    }
    cout << d << "\n";
}

void find_xy(int n, ll d) {
    ll x = 1, y = 1;
     d--;

    for (int k = n; k >= 1; --k) {
        ll mid = (1LL << (k - 1));
        ll S = (1LL << (2 * (k - 1)));

        ll quadrant = d / S;
        d %= S;

        if (quadrant == 0) {
        } else if (quadrant == 1) {
            x += mid;
            y += mid;
        } else if (quadrant == 2) {
            x += mid;
        } else {
            y += mid;
        }
    }
    cout << x << " " << y << "\n";
}

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string type;
        cin >> type;
        if (type == "->") {
            ll x, y;
            cin >> x >> y;
            find_d(n, x, y);
        } else {
            ll d;
            cin >> d;
            find_xy(n, d);
        }
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

