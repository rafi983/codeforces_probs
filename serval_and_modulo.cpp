#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n), b(n);
    long long sum_a = 0;
    long long max_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
        max_a = max(max_a, a[i]);
    }
    long long sum_b = 0;
    long long max_b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
        max_b = max(max_b, b[i]);
    }

    sort(b.begin(), b.end());

    if (sum_a == sum_b) {
        vector<long long> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        if (sorted_a == b) {
            cout << max_a + 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    if (sum_a < sum_b) {
        cout << -1 << "\n";
        return;
    }

    long long diff = sum_a - sum_b;
    vector<long long> divisors;
    for (long long i = 1; i * i <= diff; ++i) {
        if (diff % i == 0) {
            divisors.push_back(i);
            if (i * i != diff) {
                divisors.push_back(diff / i);
            }
        }
    }

    // Check divisors
    for (long long k : divisors) {
        if (k <= max_b) continue;
        if (k > 1000000000LL) continue;

        // Check if this k works
        vector<long long> current_rems(n);
        for(int i=0; i<n; ++i) {
            current_rems[i] = a[i] % k;
        }
        sort(current_rems.begin(), current_rems.end());

        if (current_rems == b) {
            cout << k << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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

