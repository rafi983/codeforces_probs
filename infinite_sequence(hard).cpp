#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
ll l, r;
vector<int> a;
vector<int> S;
vector<ll> pre_S_sum;
vector<ll> pre_a_sum;
int C_odd;

int GetS(ll k) {
    if (k <= n) return S[k];

    int xor_val = 0;
    while (k > n && k % 2 == 0) {
        k /= 2;
        xor_val ^= C_odd;
    }

    if (k > n) {
        return C_odd ^ xor_val;
    }
    // k <= n
    return S[k] ^ xor_val;
}

ll PrefixSumS(ll Y) {
    if (Y <= n) return pre_S_sum[Y];

    ll odd_count = (Y + 1) / 2 - (n + 1) / 2;
    ll odd_sum = odd_count * C_odd;

    ll L_k = n / 2 + 1;
    ll R_k = Y / 2;

    ll even_sum = 0;
    if (L_k <= R_k) {
        ll range_len = R_k - L_k + 1;
        ll diff = PrefixSumS(R_k) - PrefixSumS(L_k - 1);

        if (C_odd == 1) {
            even_sum = range_len - diff;
        } else {
            even_sum = diff;
        }
    }

    return pre_S_sum[n] + odd_sum + even_sum;
}

ll PrefixSumA(ll Y) {
    if (Y <= n) return pre_a_sum[Y];


    ll k_min = (n + 1) / 2; // Since n is odd, this is exact
    ll k_max = Y / 2;

    if (k_min > k_max) return pre_a_sum[n]; // Should generally not happen for Y > n

    ll total_S = PrefixSumS(k_max) - PrefixSumS(k_min - 1);
    ll res = pre_a_sum[n] + 2 * total_S;


    if (Y % 2 == 0) {
        res -= GetS(k_max);
    }

    return res;
}

void solve() {
    if (!(cin >> n >> l >> r)) return;
    a.assign(n + 2, 0);
    S.assign(n + 2, 0);
    pre_S_sum.assign(n + 2, 0);
    pre_a_sum.assign(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        S[i] = S[i-1] ^ a[i];
        pre_S_sum[i] = pre_S_sum[i-1] + S[i];
        pre_a_sum[i] = pre_a_sum[i-1] + a[i];
    }

    if (n % 2 == 0) {
        n++;
        a[n] = S[n/2]; // a_{n} = S_{n/2} using new n (which was old n+1)
        S[n] = S[n-1] ^ a[n];
        pre_S_sum[n] = pre_S_sum[n-1] + S[n];
        pre_a_sum[n] = pre_a_sum[n-1] + a[n];
    }

    C_odd = S[n];

    cout << PrefixSumA(r) - PrefixSumA(l - 1) << "\n";
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
