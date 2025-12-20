#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll lowbit(ll x) {
    return x & -x;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    if (l == r) {
        cout << 0 << "\n";
        return;
    }

    ll xor_val = l ^ r;
    int k = 63 - __builtin_clzll((unsigned long long)xor_val);

    ll S = 1LL << k;


    ll m1 = (l & ~(S - 1)) + S;
    ll M0 = m1 - 1;

    ll lenA = M0 - l + 1;
    ll lenB = r - m1 + 1;

    ll ans = min(lowbit(lenA), lowbit(lenB)) - 1;

    if (lenA == lenB) {
        ans += lowbit(lenA);
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
