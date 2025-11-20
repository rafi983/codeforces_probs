#include <bits/stdc++.h>
using namespace std;

static inline unsigned long long sumDigitsUpto(unsigned long long n) {
    if ((long long)n < 0) return 0ULL;
    unsigned long long res = 0ULL;
    unsigned long long factor = 1ULL;
    while (factor <= n) {
        unsigned long long lower = n % factor;
        unsigned long long cur = (n / factor) % 10ULL;
        unsigned long long higher = n / (factor * 10ULL);
        res += higher * 45ULL * factor;
        res += (cur * (cur - 1ULL) / 2ULL) * factor;
        res += cur * (lower + 1ULL);
        factor *= 10ULL;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXD = 18;
    unsigned long long pw10[MAXD + 1];
    pw10[0] = 1ULL;
    for (int i = 1; i <= MAXD; ++i) pw10[i] = pw10[i - 1] * 10ULL;

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned long long k;
        cin >> k;

        unsigned __int128 total = 0; // use wide accumulator during calc
        unsigned long long rem = k;

        for (int d = 1; d <= MAXD && rem > 0; ++d) {
            unsigned __int128 blockDigits128 = (unsigned __int128)d * 9ULL * pw10[d - 1];
            unsigned long long blockDigits = (blockDigits128 > (unsigned __int128)ULLONG_MAX) ? ULLONG_MAX : (unsigned long long)blockDigits128;

            unsigned __int128 Sd128 = 0;
            if (d == 1) {
                Sd128 = 45;
            } else {
                Sd128 = (unsigned __int128)45 * pw10[d - 2] * (unsigned long long)(9 * d + 1);
            }

            if (rem >= blockDigits) {
                total += Sd128;
                rem -= blockDigits;
                continue;
            }

            unsigned long long start = pw10[d - 1];
            unsigned long long K = rem; // digits needed in this block
            unsigned long long q = K / d; // full numbers
            int r = (int)(K % d); // digits from next number

            if (q > 0) {
                unsigned long long A = start;
                unsigned long long B = start + q - 1ULL;
                total += (unsigned __int128)(sumDigitsUpto(B) - sumDigitsUpto(A - 1ULL));
            }
            if (r > 0) {
                unsigned long long cur = start + q;
                string s = to_string(cur);
                for (int i = 0; i < r; ++i) total += (unsigned)(s[i] - '0');
            }

            rem = 0;
        }

        unsigned long long ans = (unsigned long long)total;
        cout << ans << '\n';
    }
    return 0;
}

