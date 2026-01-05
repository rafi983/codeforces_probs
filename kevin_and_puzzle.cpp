#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> H(n + 1, 0);
    H[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if (a[i-1] == a[i]) {
            H[i] = (H[i] + H[i-1]) % MOD;
        }
        if (i >= 2) {
            if (a[i-2] + 1 == a[i]) {
                H[i] = (H[i] + H[i-2]) % MOD;
            }
        }
    }

    int ans = (H[n] + H[n-1]) % MOD;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

