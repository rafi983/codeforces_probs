#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k, p;
        cin >> n >> k >> p;
        if (k == 0) {
            cout << 0 << '\n';
            continue;
        }
        long long need = (llabs(k) + p - 1) / p; // ceil(|k|/p)
        if (need <= n) cout << need << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}

