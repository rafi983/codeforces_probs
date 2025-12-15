#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int MOD = 998244353;

int omega[MAXN];
int cnt[MAXN][8]; // cnt[g][v]
long long Count[MAXN][15]; // Count[g][S]
int freq[MAXN];
long long pow_cache[25];

void sieve() {
    for (int i = 2; i < MAXN; ++i) {
        if (omega[i] == 0) { // i is prime
            for (int j = i; j < MAXN; j += i) {
                omega[j]++;
            }
        }
    }
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    if (base < 0) base += MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    for (int b = -7; b <= 14; ++b) {
        pow_cache[b + 7] = power(b, k);
    }

    for (int i = 0; i <= n; ++i) {
        freq[i] = 0;
        for (int v = 0; v < 8; ++v) cnt[i][v] = 0;
        for (int s = 0; s < 15; ++s) Count[i][s] = 0;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (int x = 1; x <= n; ++x) {
        if (freq[x] == 0) continue;
        int w = omega[x];
        for (int g = 1; g * g <= x; ++g) {
            if (x % g == 0) {
                cnt[g][w] += freq[x];
                if (g * g != x) {
                    cnt[x / g][w] += freq[x];
                }
            }
        }
    }

    long long total_ans = 0;

    for (int g = n; g >= 1; --g) {
        for (int S = 0; S <= 14; ++S) {
            long long pairs = 0;
            for (int u = 0; u <= S; ++u) {
                int v = S - u;
                if (v < 0 || v > 7 || u > 7) continue;
                if (u < v) {
                    pairs = (pairs + (long long)cnt[g][u] * cnt[g][v]) % MOD;
                } else if (u == v) {
                    long long c = cnt[g][u];
                    pairs = (pairs + c * (c - 1) / 2) % MOD;
                }
            }
            Count[g][S] = pairs;
        }

        for (int h = 2 * g; h <= n; h += g) {
            for (int S = 0; S <= 14; ++S) {
                Count[g][S] = (Count[g][S] - Count[h][S] + MOD) % MOD;
            }
        }

        int w_g = omega[g];
        for (int S = 0; S <= 14; ++S) {
            if (Count[g][S] == 0) continue;
            int base = S - w_g;
            if (base >= -7 && base <= 14) {
                total_ans = (total_ans + Count[g][S] * pow_cache[base + 7]) % MOD;
            }
        }
    }

    cout << total_ans << "\n";
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

