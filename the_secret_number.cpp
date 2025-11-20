#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned long long n;
        cin >> n;
        vector<unsigned long long> xs;
        unsigned long long p = 1ULL;
        for (int k = 1; k <= 18; ++k) {
            p *= 10ULL;
            unsigned long long d = p + 1ULL;
            if (d > n) break;
            if (n % d == 0ULL) {
                xs.push_back(n / d);
            }
        }
        sort(xs.begin(), xs.end());
        if (xs.empty()) {
            cout << 0 << '\n';
        } else {
            cout << xs.size() << '\n';
            for (size_t i = 0; i < xs.size(); ++i) {
                if (i) cout << ' ';
                cout << xs[i];
            }
            cout << '\n';
        }
    }
    return 0;
}

