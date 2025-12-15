#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long k = n / 15;
    long long rem = n % 15;
    long long ans = k * 3 + min(rem + 1, 3LL);
    cout << ans << endl;
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

