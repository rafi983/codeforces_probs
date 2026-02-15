#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long l, r, k;
    if (!(cin >> l >> r >> k)) return;
    long long max_k_multiple = r / k;
    if (max_k_multiple < l) {
        cout << 0 << endl;
    } else {
        cout << max_k_multiple - l + 1 << endl;
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

