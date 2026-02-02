#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>

using namespace std;

struct Element {
    int idx;
    long long val;
};

bool check(int T, int n, long long k, const vector<long long>& diffs, long long sum_a) {
    if (T == 0) {
        return sum_a <= k;
    }

    deque<Element> dq;
    long long required_removals = 0;


    for (int i = 0; i < n; ++i) {
        // 1. Add new surplus
        if (diffs[i] > 0) {
            dq.push_back({i, diffs[i]});
        }

        // 2. Consume capacity
        if (diffs[i] < 0) {
            long long cap = -diffs[i];
            while (cap > 0 && !dq.empty()) {
                // Sink consumes from BACK (newest)
                Element& back = dq.back();
                long long take = min(cap, back.val);
                back.val -= take;
                cap -= take;
                if (back.val == 0) {
                    dq.pop_back();
                }
            }
        }



       long long min_valid_idx = (long long)i + 2 - T;

        while (!dq.empty()) {
            Element& front = dq.front();
            if (front.idx < min_valid_idx) {
                required_removals += front.val;
                dq.pop_front();
                if (required_removals > k) return false;
            } else {
                break;
            }
        }
    }

    return required_removals <= k;
}

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<long long> a(n), b(n);
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) { cin >> a[i]; sum_a += a[i]; }
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (sum_a <= k) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> diff(n);
    long long current_prefix = 0;
    long long min_prefix = 0;
    int min_idx = -1;

    for (int i = 0; i < n; ++i) {
        diff[i] = a[i] - b[i];
        current_prefix += diff[i];
        if (current_prefix < min_prefix) {
            min_prefix = current_prefix;
            min_idx = i;
        }
    }

    // Prepare linearized diffs
    int start = (min_idx + 1) % n;
    vector<long long> linear_diffs(n);
    for (int i = 0; i < n; ++i) {
        linear_diffs[i] = diff[(start + i) % n];
    }

    int low = 1, high = n;

    int ans = n;


    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, k, linear_diffs, sum_a)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
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
