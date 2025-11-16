#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long k;
        string s;
        cin >> n >> k >> s;
        if (n == 1) {
            cout << "NO\n";
            continue;
        }
        string r = s;
        reverse(r.begin(), r.end());
        if (s < r) {
            cout << "YES\n";
            continue;
        }
        if (k == 0) {
            cout << "NO\n";
            continue;
        }
        bool all_same = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[0]) {
                all_same = false;
                break;
            }
        }
        if (all_same) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

