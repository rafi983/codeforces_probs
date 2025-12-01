#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        unsigned int x;
        cin >> n >> x;

        // Compute L = smallest power of two at the lowest zero bit of x.
        unsigned int L = 1;
        while (x & L) L <<= 1;

        // Choose K with possible adjustment if we need an extra slot to add missing bits.
        int K = (int)min<unsigned int>(L, (unsigned int)n);

        auto or_upto = [](int k) -> unsigned int {
            unsigned int o = 0;
            for (int i = 0; i < k; ++i) o |= (unsigned int)i;
            return o;
        };

        unsigned int OR0 = or_upto(K);
        if (OR0 != x && K == n) {
            // Reserve one slot to add missing bits.
            K = (int)min<unsigned int>(L, (unsigned int)(n - 1));
            OR0 = or_upto(K);
        }

        vector<unsigned int> a;
        a.reserve(n);

        // Add 0..K-1
        for (int i = 0; i < K; ++i) a.push_back((unsigned int)i);

        // If missing bits remain, add them as a single number.
        if (OR0 != x) {
            unsigned int M = x ^ OR0; // x & ~OR0
            a.push_back(M);
        }

        // Fill the rest with zeros.
        while ((int)a.size() < n) a.push_back(0u);

        // Output
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}