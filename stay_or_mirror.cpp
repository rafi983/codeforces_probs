#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> f;

    explicit BIT(int n) : n(n), f(n + 1, 0) {}

    void add(int i, int v) {
        for (; i <= n; i += i & -i) {
            f[i] += v;
        }
    }

    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) {
            s += f[i];
        }
        return s;
    }

    int range(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) {
        return 0;
    }

    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        BIT bit(n);
        vector<int> L(n), R(n);
        long long inv = 0;

        for (int i = 0; i < n; ++i) {
            int less = bit.sum(p[i] - 1);
            L[i] = i - less;
            inv += L[i];
            bit.add(p[i], 1);
        }

        bit = BIT(n);

        for (int i = n - 1; i >= 0; --i) {
            int greater = (bit.sum(n) - bit.sum(p[i]));
            R[i] = greater;
            bit.add(p[i], 1);
        }

        long long ans = inv;

        for (int i = 0; i < n; ++i) {
            int coeff = R[i] - L[i];
            if (coeff < 0) {
                ans += coeff;
            }
        }

        cout << ans << ' ' << '\n';
    }

    return 0;
}
