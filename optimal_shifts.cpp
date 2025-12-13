#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int first_one = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                first_one = i;
                break;
            }
        }

        if (first_one == -1) {
            cout << 0 << "\n";
            continue;
        }

        int mx_gap = 0;
        int cnt = 0;

        for (int step = 0; step < n; ++step) {
            int idx = (first_one + step) % n;
            if (s[idx] == '0') {
                cnt++;
            } else {
                mx_gap = max(mx_gap, cnt);
                cnt = 0;
            }
        }

        mx_gap = max(mx_gap, cnt);
        cout << mx_gap << "\n";
    }

    return 0;
}
