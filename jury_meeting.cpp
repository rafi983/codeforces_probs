#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 998244353;
const int MAXN = 200000;

static long long fact[MAXN + 5];
static int A[MAXN + 5];

long long modpow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        int mx = 0, cntmx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            if (A[i] > mx) {
                mx = A[i];
                cntmx = 1;
            } else if (A[i] == mx) {
                cntmx++;
            }
        }

        if (cntmx >= 2) {
            cout << fact[n] << endl;
            continue;
        }

        int smax = 0, cnts = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != mx && A[i] > smax) {
                smax = A[i];
            }
        }

        if (mx - smax > 1) {
            cout << "0" << endl;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (A[i] == smax) {
                cnts++;
            }
        }

        long long ans = fact[n];
        ans = ans * cnts % MOD;
        ans = ans * modpow(cnts + 1, MOD - 2) % MOD;
        cout << ans << endl;
    }

    return 0;
}

