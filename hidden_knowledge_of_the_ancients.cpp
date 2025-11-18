#include <bits/stdc++.h>
using namespace std;

static long long countAtMostWithLenCap(const vector<int>& a, int K, int MaxLen, int M) {
    if (K <= 0 || MaxLen <= 0) return 0LL;
    const int n = (int)a.size();
    vector<int> cnt(M, 0);
    int distinct = 0;
    int L = 0;
    long long ans = 0;
    for (int R = 0; R < n; ++R) {
        if (cnt[a[R]]++ == 0) ++distinct;
        while (distinct > K) {
            if (--cnt[a[L]] == 0) --distinct;
            ++L;
        }
        int leftBound = max(L, R - MaxLen + 1);
        if (leftBound <= R) ans += (R - leftBound + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k, Lmin, Rmax;
        cin >> n >> k >> Lmin >> Rmax;
        vector<long long> orig(n);
        for (int i = 0; i < n; ++i) cin >> orig[i];

        vector<long long> vals = orig;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int M = (int)vals.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (int)(lower_bound(vals.begin(), vals.end(), orig[i]) - vals.begin());
        }

        auto atMostInRange = [&](int K, int lenCap) -> long long {
            return countAtMostWithLenCap(a, K, lenCap, M);
        };

        long long ans = 0;
        long long A_k_R = atMostInRange(k, Rmax);
        long long A_k_Lm1 = atMostInRange(k, Lmin - 1);
        long long A_km1_R = atMostInRange(k - 1, Rmax);
        long long A_km1_Lm1 = atMostInRange(k - 1, Lmin - 1);
        ans = (A_k_R - A_k_Lm1) - (A_km1_R - A_km1_Lm1);

        cout << ans << '\n';
    }
    return 0;
}

