#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long min_prev = b[0];
    bool possible = true;

    for (int i = 1; i < n; ++i) {
        long long t = b[i];
        long long limit = min_prev;

        // Try to decompose t
        while (t > 0) {
            long long x = min(t, limit);
            if (x <= t - x) {
                possible = false;
                break;
            }
            t -= x;
            limit = x - 1;
        }

        if (!possible) break;
        min_prev = min(min_prev, b[i]);
    }

    if (possible) cout << "YES\n";
    else cout << "NO\n";
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

