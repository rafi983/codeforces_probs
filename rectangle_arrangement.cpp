#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int max_w = 0;
    int max_h = 0;
    for (int i = 0; i < n; ++i) {
        int w, h;
        cin >> w >> h;
        if (w > max_w) max_w = w;
        if (h > max_h) max_h = h;
    }
    cout << 2 * (max_w + max_h) << endl;
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
