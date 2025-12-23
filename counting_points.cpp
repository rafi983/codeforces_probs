#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long m;
    if (!(cin >> n >> m)) return;

    vector<long long> x(n);
    for(int i=0; i<n; ++i) cin >> x[i];

    vector<long long> r(n);
    for(int i=0; i<n; ++i) cin >> r[i];

    vector<pair<long long, int>> points;
    // Total points is sum(2*r_i + 1) = 2*m + n
    // Since sum of m over test cases is 2e5, this is safe.
    points.reserve(2 * m + n);

    for(int i=0; i<n; ++i) {
        long long cx = x[i];
        long long rad = r[i];
        long long rad_sq = rad * rad;

        for(long long dx = -rad; dx <= rad; ++dx) {
            long long dy_sq = rad_sq - dx * dx;
            int h = (int)sqrt(dy_sq);
            points.push_back({cx + dx, h});
        }
    }

    sort(points.begin(), points.end());

    long long total_points = 0;
    if (points.empty()) {
        cout << 0 << "\n";
        return;
    }

    long long current_x = points[0].first;
    int max_h = points[0].second;

    for(size_t i = 1; i < points.size(); ++i) {
        if (points[i].first != current_x) {
            total_points += 2LL * max_h + 1;
            current_x = points[i].first;
            max_h = points[i].second;
        } else {
            max_h = max(max_h, points[i].second);
        }
    }
    // Add last one
    total_points += 2LL * max_h + 1;

    cout << total_points << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}

