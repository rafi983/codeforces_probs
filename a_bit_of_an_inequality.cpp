#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] ^ a[i];
    }

    long long ans = 0;

    vector<vector<int>> by_msb(32);
    for (int i = 0; i < n; ++i) {
        int msb = -1;
        if (a[i] > 0) {
            msb = 31 - __builtin_clz(a[i]);
        }
        if (msb != -1) {
            by_msb[msb].push_back(i + 1);
        }
    }

    vector<int> zeros(n + 2);
    vector<int> ones(n + 2);

    for (int b = 0; b < 30; ++b) {
        if (by_msb[b].empty()) continue;

        zeros[0] = 0;
        ones[0] = 0;
        for (int i = 0; i <= n; ++i) {
            zeros[i + 1] = zeros[i];
            ones[i + 1] = ones[i];
            if ((P[i] >> b) & 1) {
                ones[i + 1]++;
            } else {
                zeros[i + 1]++;
            }
        }

        int total_zeros = zeros[n + 1];
        int total_ones = ones[n + 1];

        for (int y : by_msb[b]) {
            long long l0 = zeros[y];
            long long l1 = ones[y];

            long long r0 = total_zeros - l0;
            long long r1 = total_ones - l1;

            ans += l0 * r0 + l1 * r1;
        }
    }

    cout << ans << endl;
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

