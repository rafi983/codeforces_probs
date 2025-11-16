#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long a, b, n;
        cin >> a >> b >> n;
        long long q = a / b;
        int ans;
        if (n <= q) ans = 1;
        else if (b == a) ans = 1;
        else ans = 2;
        cout << ans << "\n";
    }
    return 0;
}

