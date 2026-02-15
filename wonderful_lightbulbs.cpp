#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long find_odd_occurrence(vector<long long>& nums) {
    if (nums.empty()) return 0; // Should not happen based on problem constraints
    sort(nums.begin(), nums.end());

    long long current = nums[0];
    int count = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == current) {
            count++;
        } else {
            if (count % 2 != 0) {
                return current;
            }
            current = nums[i];
            count = 1;
        }
    }
    if (count % 2 != 0) {
        return current;
    }
    return 0; // Should not be reached
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> xs;
    vector<long long> sums;

    xs.reserve(n);
    sums.reserve(n);

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        xs.push_back(x);
        sums.push_back(x + y);
    }

    long long s = find_odd_occurrence(xs);
    long long s_plus_t = find_odd_occurrence(sums);

    long long t = s_plus_t - s;

    cout << s << " " << t << "\n";
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

