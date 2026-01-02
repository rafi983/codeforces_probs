#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> intervals;
    intervals.push_back({m, m});

    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;

        vector<pair<int, int>> next_intervals;
        bool spawn = false;

        for (auto p : intervals) {
            int l = p.first;
            int r = p.second;

            if (a < l) {
                next_intervals.push_back({l - 1, r});
            } else if (a > r) {
                next_intervals.push_back({l, r + 1});
            } else {
                // l <= a <= r
                if (l != r) {
                    next_intervals.push_back({l, r});
                }
                spawn = true;
            }
        }

        if (spawn) {
            next_intervals.push_back({1, 1});
            next_intervals.push_back({n, n});
        }

        if (next_intervals.empty()) {
            // Should not happen
            intervals = next_intervals;
            cout << 0 << " ";
            continue;
        }

        sort(next_intervals.begin(), next_intervals.end());

        intervals.clear();
        intervals.push_back(next_intervals[0]);

        for (size_t k = 1; k < next_intervals.size(); ++k) {
            auto& last = intervals.back();
            auto curr = next_intervals[k];

            // Check overlap or adjacent
            if (curr.first <= last.second + 1) {
                last.second = max(last.second, curr.second);
            } else {
                intervals.push_back(curr);
            }
        }

        long long count = 0;
        for (auto p : intervals) {
            count += (long long)(p.second - p.first + 1);
        }
        cout << count << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

