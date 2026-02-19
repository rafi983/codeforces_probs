#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 400005;
const int MAX_VAL = 6000000;

vector<int> primes;
long long primes_sum[MAX_N];
bool not_prime[MAX_VAL];

void precompute() {
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (!not_prime[i]) {
            for (int j = i * i; j < MAX_VAL; j += i)
                not_prime[j] = true;
        }
    }
    for (int i = 2; i < MAX_VAL; ++i) {
        if (!not_prime[i]) {
            primes.push_back(i);
            if (primes.size() >= MAX_N) break;
        }
    }
    primes_sum[0] = 0;
    for (int i = 0; i < (int)primes.size(); ++i) {
        if (i + 1 < MAX_N)
            primes_sum[i + 1] = primes_sum[i] + primes[i];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid == 0) {
            ans = max(ans, mid);
            l = mid + 1;
            continue;
        }
        if (mid > (int)primes.size()) {
            r = mid - 1;
            continue;
        }
        if (pref[mid] >= primes_sum[mid]) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << n - ans << endl;
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

