#include <bits/stdc++.h>
using namespace std;

static inline int msb_index(unsigned int x) {
    int idx = 0;
    while (x >> 1) {
        x >>= 1;
        ++idx;
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << '\n';
            continue;
        }

        int msbA = msb_index(a);
        int msbB = msb_index(b);

        if (msbB > msbA) {
            cout << -1 << '\n';
            continue;
        }

        if ((a >> msbB) & 1U) {
            unsigned int x = a ^ b;
            cout << 1 << '\n' << x << '\n';
        } else {
            unsigned int x1 = (1u << msbB);
            unsigned int a1 = a ^ x1;
            unsigned int x2 = a1 ^ b; // guaranteed x2 <= a1 now
            cout << 2 << '\n' << x1 << ' ' << x2 << '\n';
        }
    }
    return 0;
}
