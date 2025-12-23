#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    if (k % 2 != 0) {
        for (int i = 1; i < n; ++i) {
            cout << n << " ";
        }
        cout << n - 1 << "\n";
    } else {
        for (int i = 1; i <= n - 2; ++i) {
            cout << n - 1 << " ";
        }
        cout << n << " " << n - 1 << "\n";
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
