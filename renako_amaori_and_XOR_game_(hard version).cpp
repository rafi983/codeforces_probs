#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        int Xa = 0, Xb = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            Xa ^= a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            Xb ^= b[i];
        }

        int M = Xa ^ Xb;
        if (M == 0) {
            cout << "Tie\n";
            continue;
        }

        int h = 0;
        for (int k = 31; k >= 0; k--) {
            if (M & (1 << k)) {
                h = k;
                break;
            }
        }

        int lastIndex = -1;
        for (int i = 0; i < n; i++) {
            if (((a[i] ^ b[i]) >> h) & 1)
                lastIndex = i;
        }

        if ((lastIndex + 1) % 2 == 1)
            cout << "Ajisai\n";
        else
            cout << "Mai\n";
    }

    return 0;
}
