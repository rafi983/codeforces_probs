#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> divisors;
    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            divisors.push_back(i);
            if (i * i != m) {
                divisors.push_back(m / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    vector<int> counts(divisors.size(), 0);

    auto update_counts = [&](int idx, int val) {
        if (idx < 0 || idx >= n - 1) return;
        int u = a[idx];
        int v = a[idx+1];
        for (int i = 0; i < divisors.size(); ++i) {
            int d = divisors[i];
            if (u % d > v % d) {
                counts[i] += val;
            }
        }
    };

    for (int i = 0; i < n - 1; ++i) {
        update_counts(i, 1);
    }

    for (int k = 0; k < q; ++k) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            --i;

            update_counts(i - 1, -1);
            update_counts(i, -1);

            a[i] = x;

            update_counts(i - 1, 1);
            update_counts(i, 1);

        } else {
            int k_val;
            cin >> k_val;
            int g = gcd(k_val, m);

            auto it = lower_bound(divisors.begin(), divisors.end(), g);
            int idx = distance(divisors.begin(), it);

            if (counts[idx] < m / g) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

