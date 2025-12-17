#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    long long R0, X, D;
    int n;
    if (!(cin >> R0 >> X >> D >> n)) return;
    string s;
    cin >> s;

    long long currentR = R0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (currentR < X) {
            ans += (n - i);
            break;
        }

        if (s[i] == '1') {
            ans++;
            currentR = max(0LL, currentR - D);
        }
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

