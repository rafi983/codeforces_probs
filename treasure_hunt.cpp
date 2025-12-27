#include <iostream>

using namespace std;

void solve() {
    long long x, y, a;
    cin >> x >> y >> a;
    long long sum = x + y;
    long long rem = a % sum;
    if (x > rem) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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
