#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> counts(2 * n + 10, 0);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
        max_val = max(max_val, x);
    }

    long long s = 0;
    for (int i = 1; i <= 2 * n + 5; ++i) {
        s += counts[i];

        if (s > 0) {
            s -= 2;
            if (s < 0) {
                cout << "No" << endl;
                return;
            }
        }

        // Optimization: if we are past max_val and buffer is empty, we are done.
        if (i > max_val && s == 0) {
            break;
        }
    }

    if (s == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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

