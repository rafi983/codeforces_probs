#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    int n1 = 0, n2 = 0, n3 = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        bool r = (val <= h);
        bool c = (val <= l);
        if (r && c) {
            n1++;
        } else if (r) {
            n2++;
        } else if (c) {
            n3++;
        }
    }

    int ans = (n1 + n2 + n3) / 2;
    ans = min(ans, n1 + n2);
    ans = min(ans, n1 + n3);

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
