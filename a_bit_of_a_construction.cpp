#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    if (n == 1) {
        cout << k << endl;
        return;
    }

    long long best_val = 0;
    // Find the largest (2^p - 1) <= k
    for (int i = 0; i < 31; ++i) {
        long long val = (1LL << i) - 1;
        if (val <= k) {
            best_val = val;
        }
    }

    cout << best_val << " " << (k - best_val);
    for (int i = 2; i < n; ++i) {
        cout << " 0";
    }
    cout << endl;
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

