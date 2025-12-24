#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MAXN = 200005;
int spf[MAXN];

void sieve() {
    iota(spf, spf + MAXN, 0);
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

bool is_prime(int x) {
    return x > 1 && spf[x] == x;
}

bool is_semiprime(int x) {
    if (x <= 1) return false;
    int p = spf[x];
    int q = x / p;
    return is_prime(q);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x <= n) cnt[x]++;
    }

    long long ans = 0;
    long long sum_primes = 0;
    long long sum_sq_primes = 0;

    for (int i = 1; i <= n; ++i) {
        if (is_prime(i)) {
            sum_primes += cnt[i];
            sum_sq_primes += 1LL * cnt[i] * cnt[i];
        }
    }

    ans += (sum_primes * sum_primes - sum_sq_primes) / 2;

    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 0 && is_semiprime(i)) {
            // Case 1: pair (i, i)
            ans += 1LL * cnt[i] * (cnt[i] + 1) / 2;

            // Case 3: pair (p, i) where p divides i
            int p = spf[i];
            int q = i / p;

            if (p <= n) ans += 1LL * cnt[p] * cnt[i];
            if (p != q && q <= n) ans += 1LL * cnt[q] * cnt[i];
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

