#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    int k = 0;
    for (char c : s) {
        if (c == '1') {
            k++;
        }
    }

    int zeros = n - k;
    int ans = k * (n - 1) + zeros;
    cout << ans << "\n";
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

