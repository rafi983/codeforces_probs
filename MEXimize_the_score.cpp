#include <iostream>
#include <vector>
#include <algorithm>

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

const int MAXN = 200005;
long long fact[MAXN], invFact[MAXN];
long long pow2[MAXN];

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % 998244353;
        pow2[i] = (pow2[i - 1] * 2) % 998244353;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % 998244353;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % 998244353 * invFact[n - r] % 998244353;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<long long> P(n + 1, 1);

    long long ans = 0;
    int current_min_c = n;
    int tail = n;

    vector<long long> row_S;
    row_S.reserve(n + 2);

    for (int x = 0; x <= n; x++) {
        int cx = cnt[x];
        if (cx == 0) break; // If a number is missing, mex cannot increase further

        current_min_c = min(current_min_c, cx);


        row_S.assign(cx + 2, 0);
        for (int k = cx; k >= 1; k--) {
            row_S[k] = (row_S[k + 1] + nCr(cx, k)) % 998244353;
        }

        long long current_term_sum = 0;

        // Update P and sum
        for (int m = 1; m <= current_min_c; m++) {
            P[m] = (P[m] * row_S[m]) % 998244353;
            current_term_sum = (current_term_sum + P[m]) % 998244353;
        }

        tail -= cx;
        // The number of subsets of the tail elements (elements > x) is 2^tail
        long long contribution = (current_term_sum * pow2[tail]) % 998244353;
        ans = (ans + contribution) % 998244353;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
