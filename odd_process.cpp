#include <bits/stdc++.h>
using namespace std;

static inline bool feasible(int O_minus_1, int E_before, int y) {
    int p_low = max(0, y - E_before);
    int p_high = min(O_minus_1, y);
    if (p_low > p_high) return false;
    if (p_low == p_high && (p_low & 1)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<long long> evens;
        long long bestOdd = LLONG_MIN;
        int O = 0;

        for (long long v : a) {
            if ((v & 1LL) == 0) {
                evens.push_back(v);
            } else {
                O++;
                bestOdd = max(bestOdd, v);
            }
        }

        sort(evens.begin(), evens.end(), greater<long long>());
        int E = (int)evens.size();
        vector<long long> prefE(E + 1, 0);
        for (int i = 1; i <= E; ++i) {
            prefE[i] = prefE[i - 1] + evens[i - 1];
        }

        if (O == 0) {
            for (int k = 1; k <= n; ++k) {
                cout << 0 << (k == n ? '\n' : ' ');
            }
            continue;
        }

        int O_minus_1_even_cap = ((O - 1) / 2) * 2;

        for (int k = 1; k <= n; ++k) {
            int x = min(E, k - 1);
            long long ans = 0;
            bool got = false;

            for (int tryX = x; tryX >= max(0, x - 1); --tryX) {
                int y = k - 1 - tryX;
                int E_before = E - tryX;
                int O_minus_1 = O - 1;

                if (feasible(O_minus_1, E_before, y)) {
                    ans = bestOdd + prefE[tryX];
                    got = true;
                    break;
                }
            }

            if (!got) {
                ans = 0;
            }

            cout << ans << (k == n ? '\n' : ' ');
        }
    }

    return 0;
}
