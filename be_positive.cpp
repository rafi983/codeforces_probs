#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        int zeros = 0, negs = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x == 0) ++zeros;
            else if (x == -1) ++negs;
        }
        int ops = zeros;
        if (negs % 2) ops += 2;
        cout << ops << "\n";
    }
    return 0;
}

