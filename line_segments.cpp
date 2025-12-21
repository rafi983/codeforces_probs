#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    long long px, py, qx, qy;
    cin >> px >> py >> qx >> qy;

    long long sum_a = 0;
    long long max_a = 0;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        sum_a += a;
        if (a > max_a) max_a = a;
    }

    long long dx = px - qx;
    long long dy = py - qy;
    long long dist_sq = dx * dx + dy * dy;
    long long sum_sq = sum_a * sum_a;

    // Condition 1: D <= Sum
    if (dist_sq > sum_sq) {
        cout << "No\n";
        return;
    }

    // Condition 2: D >= 2*Max - Sum (only if 2*Max > Sum)
    if (2 * max_a > sum_a) {
        long long min_dist = 2 * max_a - sum_a;
        long long min_dist_sq = min_dist * min_dist;
        if (dist_sq < min_dist_sq) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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

