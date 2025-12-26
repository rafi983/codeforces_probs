#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (n % 2 == 0) {

        long long ans = (n + (k - 1) - 1) / (k - 1);
        cout << ans << endl;
    } else {

        long long rem = n - k;
        // Now rem is even. Steps = 1 + ceil(rem / (k-1))
        long long ans = 1 + (rem + (k - 1) - 1) / (k - 1);
        cout << ans << endl;
    }
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

