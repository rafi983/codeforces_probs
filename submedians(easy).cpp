#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Result {
    bool found;
    int l, r;
};

Result check(int n, int k, int val, const vector<int>& a) {
    vector<int> P(n + 1, 0);
    int current_P = 0;
    int min_val = 2000000000;
    int min_idx = -1;

    for (int i = 0; i < n; ++i) {
        current_P += (a[i] >= val ? 1 : -1);
        P[i + 1] = current_P;

        if (i >= k - 1) {
            int idx_to_add = i - k + 1;
            if (P[idx_to_add] < min_val) {
                min_val = P[idx_to_add];
                min_idx = idx_to_add;
            }
            if (current_P >= min_val) {
                return {true, min_idx + 1, i + 1};
            }
        }
    }
    return {false, -1, -1};
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int low = 1, high = n;
    int ans = 1;
    int final_l = 1, final_r = k;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        Result res = check(n, k, mid, a);
        if (res.found) {
            ans = mid;
            final_l = res.l;
            final_r = res.r;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << " " << final_l << " " << final_r << "\n";
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
