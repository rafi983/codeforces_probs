#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool check(int t, int n, int k, int max_val, const vector<int>& N0) {


    int limit = max_val + t + 2;
    deque<int> dq;

    auto get_B = [&](int y) {
        if (y > max_val) return y; // N0 is 0
        return N0[y] + y;
    };

    dq.push_back(1);

    int prev_Nt = -1;

    for (int x = 1; x <= limit; ++x) {

        int val_x = get_B(x);
        while (!dq.empty() && get_B(dq.back()) <= val_x) {
            dq.pop_back();
        }
        dq.push_back(x);

        // Remove old
        if (dq.front() < x - t) {
            dq.pop_front();
        }

        int max_B = get_B(dq.front());
        int current_Nt = max_B - x;

        if (x > 1) {
            if (prev_Nt - current_Nt > k) return false;
        }
        prev_Nt = current_Nt;
    }

    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int max_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }


    vector<int> cnt(max_a + 2, 0);
    for (int x : a) cnt[x]++;

    vector<int> N0(max_a + 2, 0);
    for (int i = max_a; i >= 1; --i) {
        N0[i] = N0[i+1] + cnt[i];
    }

    int low = 0, high = n;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, k, max_a, N0)) {
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

