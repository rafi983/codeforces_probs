#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check(int n, int k, const string& s, const vector<int>& a, int penalty_limit) {
    int ops = 0;
    bool active_segment = false;

    for (int i = 0; i < n; ++i) {
        if (a[i] > penalty_limit) {
            if (s[i] == 'B') {
                if (!active_segment) {
                    ops++;
                    active_segment = true;
                }
            } else { // s[i] == 'R'
                active_segment = false;
            }
        }
    }
    return ops <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    int max_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    int low = 0, high = max_a;
    int ans = max_a;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(n, k, s, a, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
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

