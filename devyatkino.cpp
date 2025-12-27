#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> combs[10];
ll pow10_arr[15];

void precompute_pow10() {
    pow10_arr[0] = 1;
    for (int i = 1; i <= 12; ++i) {
        pow10_arr[i] = pow10_arr[i - 1] * 10;
    }
}

void generate_combs(int m, int k_start, ll current_val, int target_m) {
    if (m == target_m) {
        combs[target_m].push_back(current_val);
        return;
    }

    for (int k = k_start; k <= 9; ++k) {
        generate_combs(m + 1, k, current_val + pow10_arr[k], target_m);
    }
}

void precompute_combs() {
    // We only need to check up to 8. If not found, answer is 9.
    for (int m = 1; m <= 8; ++m) {
        generate_combs(0, 1, 0, m);
    }
}

bool has7(ll n) {
    while (n > 0) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;

    if (has7(n)) {
        cout << 0 << "\n";
        return;
    }

    for (int m = 1; m <= 8; ++m) {
        for (ll val : combs[m]) {
            if (has7(n - m + val)) {
                cout << m << "\n";
                return;
            }
        }
    }

    cout << 9 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_pow10();
    precompute_combs();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
