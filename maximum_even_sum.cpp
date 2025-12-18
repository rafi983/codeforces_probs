#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b;
    if (!(cin >> a >> b)) return;
    long long p = a * b;

    if (p % 2 != 0) {

        cout << p + 1 << endl;
    } else if (p % 4 != 0) {
        // p is even but not divisible by 4. Sum is always odd.
        cout << -1 << endl;
    } else {
        // p is divisible by 4. We need x and y to be even.
        if (b % 2 != 0) {
            // b is odd, no even divisor.
            cout << -1 << endl;
        } else {
            long long ans = 2 + p / 2;

            if (a % 2 == 0) {
                ans = max(ans, a + b);
            } else {
                ans = max(ans, 2 * a + b / 2);
            }
            cout << ans << endl;
        }
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
