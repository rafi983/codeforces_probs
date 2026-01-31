#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long min_val = 2e18;
    long long max_val = -1;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a < min_val) min_val = a;
        if (a > max_val) max_val = a;
    }
    cout << max_val - min_val << endl;
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
