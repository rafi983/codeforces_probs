#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

int query_sum(const vector<int>& nodes) {
    if (nodes.empty()) return 0;
    cout << "? 1 " << nodes.size();
    for (int u : nodes) cout << " " << u;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void toggle(int u) {
    cout << "? 2 " << u << endl;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
    }

    int f1 = query_sum({1});

    if (abs(f1) == 1) {
        int v1 = f1;
        vector<int> ans(n + 1);
        ans[1] = v1;
        for (int i = 2; i <= n; ++i) {
            int fu = query_sum({i});
            ans[i] = fu - v1;
        }
        cout << "!";
        for (int i = 1; i <= n; ++i) cout << " " << ans[i];
        cout << endl;
        return;
    }

    vector<int> f(n + 1);
    f[1] = f1;
    for (int i = 2; i <= n; ++i) {
        f[i] = query_sum({i});
    }

    int vr = 0;
    vector<int> candidates;

    toggle(1);

    if (f1 == 0) {
        int new_f1 = query_sum({1});
        vr = new_f1 / 2;
        for (int i = 2; i <= n; ++i) candidates.push_back(i);
    } else {
        vr = f1 / 2;
        int target = (f1 == 2) ? 1 : -1;
        for (int i = 2; i <= n; ++i) {
            if (f[i] == target) {
                candidates.push_back(i);
            }
        }
    }

    int L = 0, R = candidates.size() - 1;
    int r_index = -1;

    while (L <= R) {
        if (L == R) {
            r_index = candidates[L];
            break;
        }

        int mid = L + (R - L) / 2;
        vector<int> query_nodes;
        for (int i = L; i <= mid; ++i) query_nodes.push_back(candidates[i]);

        int actual_sum = query_sum(query_nodes);

        int v1_old;
        if (f1 == 0) v1_old = -vr;
        else v1_old = f1 / 2;

        long long expected_sum_no_r = 0;
        for (int u : query_nodes) {
            expected_sum_no_r += (f[u] - 2 * v1_old);
        }

        if (actual_sum == expected_sum_no_r) {
            L = mid + 1;
        } else {
            R = mid;
        }
    }

    int r = r_index;
    vector<int> ans(n + 1);

    int v1_old;
    if (f1 == 0) v1_old = -vr;
    else v1_old = f1 / 2;

    ans[1] = -v1_old;
    ans[r] = vr;

    for (int i = 2; i <= n; ++i) {
        if (i == r) continue;
        ans[i] = f[i] - vr - v1_old;
    }

    cout << "!";
    for (int i = 1; i <= n; ++i) cout << " " << ans[i];
    cout << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

