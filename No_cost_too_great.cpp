#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int spf[MAXN];
int cnt[MAXN];
int cnt_plus[MAXN];

void sieve() {
    iota(spf, spf + MAXN, 0);
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> used_primes;
    bool cost0 = false;

    for (int x : a) {
        // Factorize x
        int temp = x;
        while (temp > 1) {
            int p = spf[temp];
            cnt[p]++;
            used_primes.push_back(p);
            if (cnt[p] >= 2) cost0 = true;
            while (temp % p == 0) temp /= p;
        }

        // Factorize x + 1
        temp = x + 1;
        while (temp > 1) {
            int p = spf[temp];
            cnt_plus[p]++;
            used_primes.push_back(p);
            while (temp % p == 0) temp /= p;
        }
    }

    if (cost0) {
        cout << 0 << "\n";
    } else {
        bool cost1 = false;
        for (int p : used_primes) {
            if (cnt[p] > 0 && cnt_plus[p] > 0) {
                cost1 = true;
                break;
            }
        }
        cout << (cost1 ? 1 : 2) << "\n";
    }

    for (int p : used_primes) {
        cnt[p] = 0;
        cnt_plus[p] = 0;
    }
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

