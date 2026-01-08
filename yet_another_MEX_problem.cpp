#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zaman_solver() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<bool> has_num(n + 1, false);

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= n) {
            has_num[val] = true;
        }
    }

    int overall_mex = 0;
    while (overall_mex <= n && has_num[overall_mex]) {
        overall_mex++;
    }

    cout << min(overall_mex, k - 1) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            zaman_solver();
        }
    }
    return 0;
}
