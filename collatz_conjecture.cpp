#include <iostream>

using namespace std;

void solve() {
    int k, x;
    if (!(cin >> k >> x)) return;
    long long ans = x;
    for (int i = 0; i < k; ++i) {
        ans *= 2;
    }
    cout << ans << endl;
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
