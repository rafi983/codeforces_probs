#include <iostream>

using namespace std;

void solve() {
    long long n;
    if (!(cin >> n)) return;
    long long ans = 1;
    while (n > 3) {
        n /= 4;
        ans *= 2;
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

