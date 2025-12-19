#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;

    long long low = 1, high = m;
    long long ans = m;

    while (low <= high) {
        long long mid = low + (high - low) / 2;


        long long capacity_per_row = (m / (mid + 1)) * mid + (m % (mid + 1));

        if (n * capacity_per_row >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
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

