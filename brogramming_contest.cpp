#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        int changes = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i-1]) {
                ++changes;
            }
        }

        int ans = changes + (s[0] == '1');
        cout << ans << '\n';
    }

    return 0;
}
