#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll x0 = 1, y0 = 0, zc0 = 0, zk0 = 0;
    ll x1 = 0, y1 = 1, zc1 = 0, zk1 = 0;

    ll prev_x = x0, prev_y = y0, prev_zc = zc0, prev_zk = zk0;
    ll curr_x = x1, curr_y = y1, curr_zc = zc1, curr_zk = zk1;

    ll x_n = x1, y_n = y1, zc_n = zc1, zk_n = zk1;

    for (int k = 1; k <= n; ++k) {
        // Equation index (from middle element)
        int d_idx = k % n;


        ll next_x = -2 * curr_x - prev_x;
        ll next_y = -2 * curr_y - prev_y;
        ll next_zc = 1 - 2 * curr_zc - prev_zc;
        ll next_zk = -a[d_idx] - 2 * curr_zk - prev_zk;

        prev_x = curr_x; prev_y = curr_y; prev_zc = curr_zc; prev_zk = curr_zk;
        curr_x = next_x; curr_y = next_y; curr_zc = next_zc; curr_zk = next_zk;

        if (k == n - 1) {
            x_n = curr_x; y_n = curr_y; zc_n = curr_zc; zk_n = curr_zk;
        }
    }

    ll x_np1 = curr_x;
    ll y_np1 = curr_y;
    ll zc_np1 = curr_zc;
    ll zk_np1 = curr_zk;


    ll A1 = x_n - 1;
    ll B1 = y_n;
    ll A2 = x_np1;
    ll B2 = y_np1 - 1;

    ll Det = A1 * B2 - A2 * B1;

    if (Det == 0) {
        cout << "-1\n";
        return;
    }

    // RHS form: C * K + M
    ll K1 = -zc_n;
    ll M1 = -zk_n;
    ll K2 = -zc_np1;
    ll M2 = -zk_np1;

    // Use __int128 for calculation to avoid overflow for Const terms
    __int128 A1_128 = A1, B1_128 = B1;
    __int128 A2_128 = A2, B2_128 = B2;
    __int128 K1_128 = K1, M1_128 = M1;
    __int128 K2_128 = K2, M2_128 = M2;

    __int128 Coeff0 = K1_128 * B2_128 - K2_128 * B1_128;
    __int128 Const0 = M1_128 * B2_128 - M2_128 * B1_128;

    __int128 Coeff1 = A1_128 * K2_128 - A2_128 * K1_128;
    __int128 Const1 = A1_128 * M2_128 - A2_128 * M1_128;

    // Handle negative Det by flipping signs
    if (Det < 0) {
        Det = -Det;
        Coeff0 = -Coeff0; Const0 = -Const0;
        Coeff1 = -Coeff1; Const1 = -Const1;
    }

    ll final_C = -1;

    // Iterate small remainders for C
    for (int rem = 0; rem < Det; ++rem) {
        // Evaluate numerators modulo Det
        __int128 num0 = Coeff0 * rem + Const0;
        __int128 num1 = Coeff1 * rem + Const1;

        // C works if numerators are divisible by Det
        if (num0 % Det == 0 && num1 % Det == 0) {
             ll large_base = 300000000000000000LL; // 3 * 10^17 to ensure positivity
             if (large_base % Det != 0) {
                 large_base += (Det - (large_base % Det));
             }

             final_C = large_base + rem;
             break;
        }
    }

    if (final_C == -1) {
        cout << "-1\n";
        return;
    }

    // Compute v0, v1
    ll v0 = (Coeff0 * final_C + Const0) / Det;
    ll v1 = (Coeff1 * final_C + Const1) / Det;

    vector<ll> ans(n);
    ans[0] = v0;
    if (n > 1) ans[1] = v1;

    ll val_prev = v0;
    ll val_curr = v1;

    for (int k = 1; k < n - 1; ++k) {
        int d_idx = k; // indices 1 to n-2. For k=1, use D_1. Correct.
        ll D = final_C - a[d_idx];
        ll val_next = D - 2 * val_curr - val_prev;
        ans[k+1] = val_next;

        val_prev = val_curr;
        val_curr = val_next;
    }

    // Output
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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
