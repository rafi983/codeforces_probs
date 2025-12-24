#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    cout << (1 << n) - 1;

    for (int j = 1; j <= n; ++j) {
        int k = n - j;
        int limit = 1 << (j - 1);
        int lower_mask = (1 << k) - 1;
        for (int z = 0; z < limit; ++z) {
            int val = (z << (k + 1)) | lower_mask;
            cout << " " << val;
        }
    }
    cout << "\n";
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
