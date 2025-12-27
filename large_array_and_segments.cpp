#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    long long x;
    if (!(cin >> n >> k >> x)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    long long S = pref[n];
    long long TotalSum = S * k;

    if (TotalSum < x) {
        cout << 0 << "\n";
        return;
    }

    long long Target = TotalSum - x;
    long long Q = Target / S;
    long long R = Target % S;

    // Find largest rem such that pref[rem] <= R
    // pref is sorted.
    auto it = upper_bound(pref.begin(), pref.end(), R);
    int rem = distance(pref.begin(), it) - 1;

    long long idx = Q * n + rem;


    cout << idx + 1 << "\n";
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

