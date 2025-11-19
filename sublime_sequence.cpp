#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, n;
        cin >> x >> n;
        long long ans = (n % 2 == 0) ? 0 : x;
        cout << ans;
        if (t) cout << '\n';
    }
    return 0;
}

