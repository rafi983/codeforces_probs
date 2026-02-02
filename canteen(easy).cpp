#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Element {
    long long idx;
    long long val;
};

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Calculate diffs and find start point
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

    int start = (min_idx + 1) % n;

    vector<Element> st;
    long long ans = 0;

    bool any_mass = false;
    for(long long x : a) if(x > 0) any_mass = true;
    if(!any_mass) {
        cout << 0 << "\n";
        return;
    }

    ans = 1;

    for (int i = 0; i < n; ++i) {
        int curr_idx = (start + i) % n;
        long long val = diff[curr_idx];

        if (val > 0) {
            st.push_back({(long long)i, val});
        } else if (val < 0) {
            long long cap = -val;
            while (cap > 0 && !st.empty()) {
                Element& top = st.back();
                long long take = min(cap, top.val);
                top.val -= take;
                cap -= take;

                long long dist = i - top.idx + 1;
                ans = max(ans, dist);

                if (top.val == 0) {
                    st.pop_back();
                }
            }
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
