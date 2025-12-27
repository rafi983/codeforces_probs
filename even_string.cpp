#include <iostream>
#include <vector>
#include <numeric>

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

const int MAXN = 500005;
long long fact[MAXN];
long long invFact[MAXN];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % 998244353;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % 998244353;
    }
}

void solve() {
    vector<int> c;
    int n = 0;
    for (int i = 0; i < 26; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            c.push_back(x);
            n += x;
        }
    }

    int e = (n + 1) / 2;
    int o = n / 2;

    // dp[j] = number of ways to get sum j using a subset of counts
    vector<int> dp(e + 1, 0);
    dp[0] = 1;

    for (int x : c) {
        for (int j = e; j >= x; j--) {
            dp[j] = (dp[j] + dp[j - x]) % 998244353;
        }
    }

    long long ways_to_partition = dp[e];

    long long permutations = (fact[e] * fact[o]) % 998244353;
    for (int x : c) {
        permutations = (permutations * invFact[x]) % 998244353;
    }

    long long ans = (ways_to_partition * permutations) % 998244353;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

