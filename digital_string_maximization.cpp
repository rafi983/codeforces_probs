#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        int best_j = i;
        int max_val = s[i] - '0';

        int limit = min(n, i + 10);

        for (int j = i + 1; j < limit; ++j) {
            int dist = j - i;
            int val = (s[j] - '0') - dist;

            if (val > max_val) {
                max_val = val;
                best_j = j;
            }
        }

        if (best_j > i) {
            char chosen = s[best_j];
            for (int k = best_j; k > i; --k) {
                s[k] = s[k-1];
            }
            s[i] = chosen - (best_j - i);
        }
    }
    cout << s << "\n";
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

