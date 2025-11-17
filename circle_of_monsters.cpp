#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        vector<long long> b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }

        long long total = 0;
        long long best_start = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long prev_explosion = b[(i - 1 + n) % n];
            long long needed = max(0LL, a[i] - prev_explosion);
            total += needed;
            long long candidate = a[i] - needed;
            best_start = min(best_start, candidate);
        }

        cout << total + best_start << '\n';
    }

    return 0;
}

