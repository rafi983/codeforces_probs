#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if ((int)s.size() != n) s = s.substr(0, n);
        char target = s.back();
        int ops = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != target) ++ops;
        }
        cout << ops << "\n";
    }
    return 0;
}

