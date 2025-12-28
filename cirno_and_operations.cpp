#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_sum = accumulate(a.begin(), a.end(), 0LL);

    while (n > 1) {
        vector<long long> next_a(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            next_a[i] = a[i+1] - a[i];
        }
        a = next_a;
        n--;
        long long current_sum = accumulate(a.begin(), a.end(), 0LL);
        max_sum = max(max_sum, abs(current_sum));
    }

    cout << max_sum << endl;
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

