#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        bool infinite = false;

        for (int i = 0; i + 1 < n; ++i) {
            if ((s[i] == '>' || s[i] == '*') && (s[i + 1] == '<' || s[i + 1] == '*')) {
                infinite = true;
                break;
            }
        }

        if (infinite) {
            cout << "-1\n";
            continue;
        }

        int L = 0;
        while (L < n && s[L] == '<') {
            ++L;
        }

        int R = 0;
        while (R < n && s[n - 1 - R] == '>') {
            ++R;
        }

        bool hasStar = (s.find('*') != string::npos);

        int ans = hasStar ? max(L, R) + 1 : max(L, R);
        cout << ans << '\n';
    }

    return 0;
}

