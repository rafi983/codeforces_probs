#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000005;
vector<int> primes;
bool is_composite[MAXN];

void sieve() {
    is_composite[0] = is_composite[1] = true;
    for (int p = 2; p * p < MAXN; p++) {
        if (!is_composite[p]) {
            for (int i = p * p; i < MAXN; i += p)
                is_composite[i] = true;
        }
    }
    for (int p = 2; p < MAXN; p++) {
        if (!is_composite[p]) {
            primes.push_back(p);
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    long long ans = 0;
    for (int p : primes) {
        if (p > n) break;
        ans += n / p;
    }
    cout << ans << "\n";
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

