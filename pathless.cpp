#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        long long s;
        cin >> n >> s;

        vector<int> a(n);
        long long total = 0;
        int c0 = 0, c1 = 0, c2 = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total += a[i];

            if (a[i] == 0) {
                ++c0;
            } else if (a[i] == 1) {
                ++c1;
            } else {
                ++c2;
            }
        }

        long long x = s - total;

        if (s < total) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << (i + 1 == n ? '\n' : ' ');
            }
            continue;
        }

        if (x == 1) {
            vector<int> out;
            out.reserve(n);
            out.insert(out.end(), c0, 0);
            out.insert(out.end(), c2, 2);
            out.insert(out.end(), c1, 1);

            for (int i = 0; i < n; ++i) {
                cout << out[i] << (i + 1 == n ? '\n' : ' ');
            }
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}

