#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long presses = 0;
    long long earned = 0;
    long long consumed = 0;

    for (int i = 0; i < n; ++i) {
        long long remaining_slots = n - i;
        long long height = a[i] - consumed;
        long long count = remaining_slots * height;

        if (earned + count >= k) {
            long long needed = k - earned;
            presses += needed;
            cout << presses << endl;
            return;
        } else {
            earned += count;
            presses += count + 1;
            consumed = a[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
