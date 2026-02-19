#include <iostream>

using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long sum = a + b + c;

    if (sum % 3 != 0) {
        cout << "NO" << endl;
        return;
    }

    long long target = sum / 3;

    if (a > target || b > target || c < target) {
        cout << "NO" << endl;
        return;
    }

    if (b <= target) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

