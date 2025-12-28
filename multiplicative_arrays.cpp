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

const int MAX_VAL = 100005;
const int MAX_FACT = 200;

int spf[MAX_VAL];
long long fact[MAX_FACT];
long long invFact[MAX_FACT];

void precompute() {
    for (int i = 1; i < MAX_VAL; ++i) spf[i] = i;
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_FACT; ++i) {
        fact[i] = (fact[i - 1] * i) % 998244353;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr_small(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % 998244353 * invFact[n - r] % 998244353;
}

void solve() {
    int k;
    long long n;
    if (!(cin >> k >> n)) return;

    for (int x = 1; x <= k; ++x) {
        int temp = x;
        vector<int> exponents;
        while (temp > 1) {
            int p = spf[temp];
            int count = 0;
            while (temp % p == 0) {
                temp /= p;
                count++;
            }
            exponents.push_back(count);
        }

        int D = 0;
        for (int e : exponents) D += e;

        int num_points = D + 2;
        vector<long long> y(num_points);
        long long current_sum = 0;

        y[0] = 0;

        for (int m = 1; m < num_points; ++m) {
            long long term = 1;
            for (int e : exponents) {
                term = (term * nCr_small(m + e - 1, e)) % 998244353;
            }
            current_sum = (current_sum + term) % 998244353;
            y[m] = current_sum;
        }

        if (n < num_points) {
            cout << y[n] << (x == k ? "" : " ");
            continue;
        }

        int N = D + 1;
        long long ans = 0;

        vector<long long> pre(N + 1);
        vector<long long> suf(N + 1);

        pre[0] = 1;
        for (int i = 0; i < N; ++i) {
            pre[i + 1] = (pre[i] * ((n - i) % 998244353)) % 998244353;
        }

        suf[N] = 1;
        for (int i = N; i > 0; --i) {
            suf[i - 1] = (suf[i] * ((n - i) % 998244353)) % 998244353;
        }

        for (int j = 0; j <= N; ++j) {
            long long num = (pre[j] * suf[j]) % 998244353;
            long long den = (invFact[j] * invFact[N - j]) % 998244353;
            if ((N - j) % 2 == 1) {
                den = (998244353 - den) % 998244353;
            }

            long long term = (y[j] * num) % 998244353;
            term = (term * den) % 998244353;
            ans = (ans + term) % 998244353;
        }

        cout << ans << (x == k ? "" : " ");
    }
    cout << endl;
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

