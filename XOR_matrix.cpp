#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

long long nCr2(long long n) {
    if (n < 2) return 0;
    long long res = n % MOD;
    res = (res * ((n - 1) % MOD)) % MOD;
    res = (res * modInverse(2)) % MOD;
    return res;
}

int A_val, B_val;
long long memo[32][16];

long long dp(int bit, int mask) {
    if (bit < 0) return 1;
    if (memo[bit][mask] != -1) return memo[bit][mask];

    long long res = 0;
    int a_bit = (A_val >> bit) & 1;
    int b_bit = (B_val >> bit) & 1;

    // Iterate over all 8 valid tuples (bu, bv, bp, bq) with XOR sum 0
    // 0000, 0011, 0101, 0110, 1001, 1010, 1100, 1111
    int valid_tuples[] = {0, 3, 5, 6, 9, 10, 12, 15};

    for (int t : valid_tuples) {
        int bu = (t >> 3) & 1;
        int bv = (t >> 2) & 1;
        int bp = (t >> 1) & 1;
        int bq = t & 1;

        int tight_u = (mask >> 3) & 1;
        int tight_v = (mask >> 2) & 1;
        int tight_p = (mask >> 1) & 1;
        int tight_q = mask & 1;

        if (tight_u && bu > a_bit) continue;
        if (tight_v && bv > a_bit) continue;
        if (tight_p && bp > b_bit) continue;
        if (tight_q && bq > b_bit) continue;

        int new_mask = 0;
        if (tight_u && (bu == a_bit)) new_mask |= 8;
        if (tight_v && (bv == a_bit)) new_mask |= 4;
        if (tight_p && (bp == b_bit)) new_mask |= 2;
        if (tight_q && (bq == b_bit)) new_mask |= 1;

        res = (res + dp(bit - 1, new_mask)) % MOD;
    }

    return memo[bit][mask] = res;
}

void solve() {
    long long n, m, A, B;
    cin >> n >> m >> A >> B;

    A_val = A;
    B_val = B;

    // Reset memo
    for(int i=0; i<32; ++i)
        for(int j=0; j<16; ++j)
            memo[i][j] = -1;

    long long S = dp(29, 15); // Start from bit 29, all tight

    long long term_sub = ((A + 1) % MOD * ((B + 1) % MOD)) % MOD;
    long long sum_NAB = (S - term_sub + MOD) % MOD;
    sum_NAB = (sum_NAB * modInverse(4)) % MOD;

    long long pow2n = power(2, n);
    long long pow2m = power(2, m);
    long long term2n_2 = (pow2n - 2 + MOD) % MOD;
    long long term2m_2 = (pow2m - 2 + MOD) % MOD;

    long long ans = 0;

    // Case 1
    ans = (ans + term_sub) % MOD;

    // Case 2
    long long waysB2 = nCr2(B + 1);
    long long term2 = ((A + 1) % MOD * waysB2) % MOD;
    term2 = (term2 * term2m_2) % MOD;
    ans = (ans + term2) % MOD;

    // Case 3
    long long waysA2 = nCr2(A + 1);
    long long term3 = ((B + 1) % MOD * waysA2) % MOD;
    term3 = (term3 * term2n_2) % MOD;
    ans = (ans + term3) % MOD;

    // Case 4
    long long term4 = (term2n_2 * term2m_2) % MOD;
    term4 = (term4 * sum_NAB) % MOD;
    ans = (ans + term4) % MOD;

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

