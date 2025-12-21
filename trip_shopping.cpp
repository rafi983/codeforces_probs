#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int l, r;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.l < b.l;
}

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long current_sum = 0;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; ++i) {
        intervals[i].l = min((int)a[i], (int)b[i]);
        intervals[i].r = max((int)a[i], (int)b[i]);
        current_sum += (long long)(intervals[i].r - intervals[i].l);
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    long long min_gap = 2000000000LL;
    int max_r = intervals[0].r;
    bool intersection_found = false;

    for (int i = 1; i < n; ++i) {
        if (intervals[i].l <= max_r) {
            intersection_found = true;
            break;
        } else {
            long long gap = intervals[i].l - max_r;
            if (gap < min_gap) {
                min_gap = gap;
            }
        }
        max_r = max(max_r, intervals[i].r);
    }

    if (intersection_found) {
        cout << current_sum << "\n";
    } else {
        cout << current_sum + 2 * min_gap << "\n";
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

