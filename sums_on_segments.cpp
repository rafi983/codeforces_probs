#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


pair<long long, long long> get_min_max_subarray_sum(const vector<int>& arr) {
    long long min_so_far = 0;
    long long max_so_far = 0;
    long long curr_min = 0;
    long long curr_max = 0;

    for (int x : arr) {
        curr_max = max(0LL, curr_max + x);
        max_so_far = max(max_so_far, curr_max);

        curr_min = min(0LL, curr_min + x);
        min_so_far = min(min_so_far, curr_min);
    }
    return {min_so_far, max_so_far};
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    int special_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1) {
            special_idx = i;
        }
    }

    vector<pair<long long, long long>> intervals;

    if (special_idx == -1) {
        intervals.push_back(get_min_max_subarray_sum(a));
    } else {
        // Left part
        vector<int> left_part;
        left_part.reserve(special_idx);
        for(int i=0; i<special_idx; ++i) left_part.push_back(a[i]);
        intervals.push_back(get_min_max_subarray_sum(left_part));

        // Right part
        vector<int> right_part;
        right_part.reserve(n - 1 - special_idx);
        for(int i=special_idx+1; i<n; ++i) right_part.push_back(a[i]);
        intervals.push_back(get_min_max_subarray_sum(right_part));

        // Part containing special element
        long long x = a[special_idx];

        // Suffixes of left
        long long min_suf = 0, max_suf = 0;
        long long curr = 0;
        for (int i = special_idx - 1; i >= 0; --i) {
            curr += a[i];
            min_suf = min(min_suf, curr);
            max_suf = max(max_suf, curr);
        }

        // Prefixes of right
        long long min_pref = 0, max_pref = 0;
        curr = 0;
        for (int i = special_idx + 1; i < n; ++i) {
            curr += a[i];
            min_pref = min(min_pref, curr);
            max_pref = max(max_pref, curr);
        }

        intervals.push_back({x + min_suf + min_pref, x + max_suf + max_pref});
    }

    // Merge intervals
    sort(intervals.begin(), intervals.end());

    vector<pair<long long, long long>> merged;
    if (!intervals.empty()) {
        merged.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            pair<long long, long long>& last = merged.back();
            // Merge if overlapping or adjacent
            if (intervals[i].first <= last.second + 1) {
                last.second = max(last.second, intervals[i].second);
            } else {
                merged.push_back(intervals[i]);
            }
        }
    }

    // Count total distinct sums
    long long count = 0;
    for (auto p : merged) {
        count += (p.second - p.first + 1);
    }

    cout << count << "\n";
    for (size_t i = 0; i < merged.size(); ++i) {
        for (long long val = merged[i].first; val <= merged[i].second; ++val) {
            cout << val << " ";
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

