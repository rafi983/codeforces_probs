#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;

    int c0 = 0, c1 = 0, c2 = 0;
    for (char c : s) {
        if (c == '0') c0++;
        else if (c == '1') c1++;
        else c2++;
    }

    int min_L = c0;
    int min_R = c1;
    int max_L = c0 + c2;
    int max_R = c1 + c2;

    string res = "";
    if (n == k) {
        for (int i = 0; i < n; ++i) res += '-';
    } else {
        int p_start = min_L + 1;
        int p_end = n - min_R;
        int d_start = max_L + 1;
        int d_end = n - max_R;

        for (int i = 1; i <= n; ++i) {
            if (i < p_start || i > p_end) {
                res += '-';
            } else if (i >= d_start && i <= d_end) {
                res += '+';
            } else {
                res += '?';
            }
        }
    }
    cout << res << "\n";
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

