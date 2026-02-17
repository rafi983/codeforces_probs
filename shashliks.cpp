#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long k, a, b, x, y;
    if (!(cin >> k >> a >> b >> x >> y)) return;

    long long ans = 0;

    if (k >= a) {
        ans = max(ans, 1 + (k - a) / x);
    }

    if (k >= b) {
        ans = max(ans, 1 + (k - b) / y);
    }

    long long v1 = a - x;
    long long v2 = b - y;

    long long req_P, cost_P, v_P;
    long long req_Q, cost_Q, v_Q;

    if (v1 >= v2) {
        req_P = a; cost_P = x; v_P = v1;
        req_Q = b; cost_Q = y; v_Q = v2;
    } else {
        req_P = b; cost_P = y; v_P = v2;
        req_Q = a; cost_Q = x; v_Q = v1;
    }



    if (cost_P <= cost_Q) {
        if (k > v_P) {
            long long max_nP = (k - v_P) / cost_P;
            if (max_nP >= 1) {

                long long current_nP = max_nP;

                long long cost_needed_for_1Q = cost_Q;


                long long limit_c2 = k - v_Q - cost_Q;
                if (limit_c2 >= cost_P) {
                    long long max_nP_c2 = limit_c2 / cost_P;
                    long long n_P = min(max_nP, max_nP_c2);

                    if (n_P >= 1) {
                        long long rem = k - v_Q - n_P * cost_P;
                        long long n_Q = rem / cost_Q;
                        ans = max(ans, n_P + n_Q);
                    }
                }
            }
        }
    } else {
        long long n_P = 1;
        if (1 * cost_P <= k - v_P) {
            long long rem = k - v_Q - cost_P;
            if (rem >= cost_Q) {
                long long n_Q = rem / cost_Q;
                ans = max(ans, n_P + n_Q);
            }
        }
    }

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
