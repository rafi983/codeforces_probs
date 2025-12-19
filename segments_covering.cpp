#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<pair<int, long long>>> segments_by_end(m + 1);
    long long base_prob = 1;

    for (int i = 0; i < n; ++i) {
        int l, r;
        long long p, q;
        cin >> l >> r >> p >> q;

        long long prob = (p * modInverse(q)) % 998244353;
        long long not_prob = (1 - prob + 998244353) % 998244353;

        base_prob = (base_prob * not_prob) % 998244353;

        long long weight = (prob * modInverse(not_prob)) % 998244353;
        segments_by_end[r].push_back({l, weight});
    }

    vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (auto& seg : segments_by_end[i]) {
            int l = seg.first;
            long long w = seg.second;
            dp[i] = (dp[i] + dp[l - 1] * w) % 998244353;
        }
    }

    cout << (dp[m] * base_prob) % 998244353 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

