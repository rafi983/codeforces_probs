#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;

    int ans = 0;
    int last_one_idx = -k - 100;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {


            if (i - last_one_idx >= k) {
                ans++;
            }
            last_one_idx = i;
        }
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
