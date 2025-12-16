#include <bits/stdc++.h>
using namespace std;


static inline long long sum_0_to_x_minus_1(long long x) {
    return x * (x - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Count frequencies up to n (mex cannot exceed n in this setting)
        vector<int> cnt(n + 2, 0);
        for (int v : a) {
            if (v <= n + 1) cnt[v]++;
        }
        int M = 0;
        while (M <= n && cnt[M] > 0) ++M; // mex of initial array
        // Compute Ucount and sum of unique values in [0..M-1]
        long long Ucount = 0;
        long long sumUnique = 0;
        int r = -1; // smallest value in [0..M-1] with cnt>=2
        for (int x = 0; x < M; ++x) {
            if (cnt[x] == 1) {
                ++Ucount;
                sumUnique += x;
            } else if (cnt[x] >= 2 && r == -1) {
                r = x;
            }
        }

        auto sumAfterOne = [&]() -> long long {
            // sum after first operation B
            long long others = (long long)n - Ucount;
            return sumUnique + others * (long long)M;
        };

        if (k == 1) {
            cout << sumAfterOne() << '\n';
            continue;
        }

        // k >= 2 cases
        if (r != -1) {
            long long rr = r;
            long long base = sum_0_to_x_minus_1(rr); // sum 0..r-1
            long long blockCount = (long long)n - rr;
            long long sumC = base + blockCount * rr;       // block r
            if (blockCount == 1) {
                cout << sumC << '\n'; // fixed point from 2nd op onward
            } else {
                if ((k % 2) == 0) {
                    cout << sumC << '\n'; // even k -> C
                } else {
                    long long sumD = base + blockCount * (rr + 1); // block r+1
                    cout << sumD << '\n'; // odd k (>=3) -> D
                }
            }
        } else { // no duplicates in [0..M-1]
            long long MM = M;
            long long sum0toMminus1 = sum_0_to_x_minus_1(MM);
            if (n == M) {
                cout << sum0toMminus1 << '\n';
            } else {
                long long blockCount = (long long)n - MM; // number of M's in B
                long long sumB = sum0toMminus1 + blockCount * MM; // after 1 op
                if (blockCount == 1) {
                    cout << sumB << '\n'; // fixed from 1st op
                } else {
                    if ((k % 2) == 1) {
                        cout << sumB << '\n'; // odd k -> B (block M)
                    } else {
                        long long sumC = sum0toMminus1 + blockCount * (MM + 1); // even k -> C (block M+1)
                        cout << sumC << '\n';
                    }
                }
            }
        }
    }
    return 0;
}

