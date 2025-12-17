#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int zeros = 0;
    for (char c : s) {
        if (c == '0') zeros++;
    }

    int ans = 0;
    for (int i = 0; i < zeros; ++i) {
        if (s[i] == '1') ans++;
    }

    cout << ans << endl;
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

