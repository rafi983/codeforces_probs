#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    long long total_ops = 0;
    for (int i = 0; i < n; ++i) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long kept = 0;
        if (b <= d) {
            kept = b + min(a, c);
        } else {
            kept = d;
        }
        total_ops += (a + b) - kept;
    }
    cout << total_ops << "\n";
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
