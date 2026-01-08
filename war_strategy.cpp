#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void zaman() {
    long long base_count, days, home_idx;
    if (!(cin >> base_count >> days >> home_idx)) return;

    long long left_cap = home_idx - 1;
    long long right_cap = base_count - home_idx;

    long long small_side = min(left_cap, right_cap);
    long long large_side = max(left_cap, right_cap);

    long long optimal_bases = 1;

    for (long long primary = 0; primary <= large_side; ++primary) {
        long long remaining_budget = days + 1 - 2 * primary;

        if (remaining_budget < 0) {
            break;
        }

        long long secondary = min({primary, small_side, remaining_budget});
        optimal_bases = max(optimal_bases, primary + secondary + 1);
    }
    cout << optimal_bases << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }
    return 0;
}
