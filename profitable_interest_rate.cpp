#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << a << endl;
    } else {
        long long ans = 2 * a - b;
        cout << max(0LL, ans) << endl;
    }
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
