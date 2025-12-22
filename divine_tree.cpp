#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long s_max(long long r, long long n) {
    return r * (r + 1) / 2 + r * (n - r);
}

void solve() {
    int n;
    long long m;
    if (!(cin >> n >> m)) return;

    int best_r = -1;
    for (int r = 1; r <= n; ++r) {
        long long min_s = (long long)r + n - 1;
        if (m < min_s) {

            cout << -1 << "\n";
            return;
        }
        if (m <= s_max(r, n)) {
            best_r = r;
            break;
        }
    }

    if (best_r == -1) {
        cout << -1 << "\n";
        return;
    }

    int r = best_r;
    cout << r << "\n";
    if (n == 1) return;

    if (r != 1) {
        cout << r << " " << 1 << "\n";
    }

    long long current_sum = s_max(r, n);
    long long diff = current_sum - m;

    vector<int> moved;

    // Move nodes > r
    if (r < n) {
        long long count_large = n - r;
        long long reduction_per_node = r - 1;
        if (reduction_per_node > 0) {
            long long take = min(count_large, diff / reduction_per_node);
            for (int i = 0; i < take; ++i) {
                moved.push_back(r + 1 + i);
            }
            diff -= take * reduction_per_node;
        }
    }

    // Move nodes < r
    int limit = r - 2;
    while (diff > 0) {
        int val = min((long long)limit, diff);
        moved.push_back(val + 1);
        diff -= val;
        limit = val - 1;
    }

    vector<bool> is_moved(n + 1, false);
    for (int x : moved) is_moved[x] = true;

    for (int i = 2; i <= n; ++i) {
        if (i == r) continue;
        if (is_moved[i]) {
            cout << 1 << " " << i << "\n";
        } else {
            cout << r << " " << i << "\n";
        }
    }
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

