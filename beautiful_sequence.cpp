#include <iostream>
#include <vector>

using namespace std;

long long MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long c1 = 0;
    long long c12 = 0;
    long long ans = 0;

    for (int x : a) {
        if (x == 1) {
            c1 = (c1 + 1) % MOD;
        } else if (x == 2) {
            c12 = (c12 * 2 + c1) % MOD;
        } else if (x == 3) {
            ans = (ans + c12) % MOD;
        }
    }

    cout << ans << "\n";
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

