#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;

ll get_b(ll v, ll a, ll k) {
    if (v < 1 - k) return 0;
    if (v < a - k) return v + k;
    if (v < a + 1) return a;
    return v;
}

ll calc_cost(ll b, ll a, ll k) {
    ll cost = b * (b + 1) / 2;
    if (b < a) {
        cost += k * (a - b);
    }
    return cost;
}

void solve() {
    int n;
    ll k;
    if (!(cin >> n >> k)) return;
    vector<ll> a(n);
    ll S = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        S += a[i];
    }

    ll low = -2000000; // 1 - k can be around -10^6
    ll high = 400000000000000LL; // Sufficiently large
    ll v_base = low;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll current_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_sum += get_b(mid, a[i], k);
            if (current_sum > S) break; // Optimization to avoid overflow and speed up
        }

        if (current_sum <= S) {
            v_base = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    ll total_cost = 0;
    ll current_count = 0;
    for (int i = 0; i < n; ++i) {
        ll b = get_b(v_base, a[i], k);
        total_cost += calc_cost(b, a[i], k);
        current_count += b;
    }

    ll needed = S - current_count;
    total_cost += needed * (v_base + 1);

    cout << total_cost << "\n";
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

