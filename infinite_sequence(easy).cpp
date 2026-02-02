#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
ll l, r;
vector<int> a;
vector<int> S;

int compute_S(ll k) {
    if (k <= n) return S[k];

    int res = S[n];
    ll L = n + 1;
    ll R = k;

    if (L % 2 != 0) {
        res ^= S[L/2];
    }

    if (R % 2 == 0) {
        res ^= compute_S(R/2);
    }

    return res;
}

void solve() {
    if (!(cin >> n >> l >> r)) return;
    a.assign(n + 1, 0);
    S.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        S[i] = S[i-1] ^ a[i];
    }

    if (l <= n) {
        cout << a[l] << "\n";
    } else {
        cout << compute_S(l/2) << "\n";
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
