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
        int pA = 0, pB = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pA ^= a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            pB ^= b[i];
        }

        if (pA == pB) {
            cout << "Tie\n";
            continue;
        }

        int oddDiff = 0, evenDiff = 0;
        int lastDiffIdx = -1;

        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                lastDiffIdx = i;
                if ((i + 1) & 1)
                    ++oddDiff;
                else
                    ++evenDiff;
            }
        }

        if (oddDiff > 0 && evenDiff == 0) {
            cout << "Ajisai\n";
            continue;
        }

        if (evenDiff > 0 && oddDiff == 0) {
            cout << "Mai\n";
            continue;
        }

        if (lastDiffIdx != -1) {
            if ((lastDiffIdx + 1) & 1)
                cout << "Ajisai\n";
            else
                cout << "Mai\n";
        } else {
            cout << "Tie\n";
        }
    }

    return 0;
}

