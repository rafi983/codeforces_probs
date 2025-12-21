#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Constraint {
    int id;
    int l, r;
};

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<pair<int, int>> type1;
    vector<Constraint> type2;

    for (int i = 0; i < q; ++i) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            type1.push_back({l, r});
        } else {
            type2.push_back({(int)type2.size(), l, r});
        }
    }

    vector<bool> must_be_ge_k(n + 1, false);
    vector<bool> in_type_2(n + 1, false);

    for (auto& p : type1) {
        for (int i = p.first; i <= p.second; ++i) {
            must_be_ge_k[i] = true;
        }
    }

    for (auto& c : type2) {
        for (int i = c.l; i <= c.r; ++i) {
            in_type_2[i] = true;
        }
    }

    vector<int> a(n + 1);
    set<int> available_indices;

    // Pre-calculate which constraints cover which index
    // Only needed for indices that end up in available_indices
    vector<vector<int>> constraints_covering(n + 1);

    for (int i = 1; i <= n; ++i) {
        if (!in_type_2[i]) {
            a[i] = k;
        } else if (must_be_ge_k[i]) {
            a[i] = k + 1;
        } else {
            a[i] = -1; // Placeholder
            available_indices.insert(i);
        }
    }

    for (const auto& c : type2) {
        for (int i = c.l; i <= c.r; ++i) {
            if (a[i] == -1) { // Only care if it's a candidate index
                constraints_covering[i].push_back(c.id);
            }
        }
    }

    sort(type2.begin(), type2.end(), [](const Constraint& a, const Constraint& b) {
        return a.r < b.r;
    });

    for (int val = 0; val < k; ++val) {
        vector<bool> satisfied(type2.size(), false);

        for (const auto& c : type2) {
            if (satisfied[c.id]) continue;

            // Find rightmost available index in [c.l, c.r]
            auto it = available_indices.upper_bound(c.r);
            if (it == available_indices.begin()) {
                // Should not happen given problem guarantees
                continue;
            }
            --it;
            int idx = *it;

            if (idx < c.l) {
                // Should not happen
                continue;
            }

            // Assign value
            a[idx] = val;
            available_indices.erase(it);

            // Mark satisfied constraints
            for (int covered_id : constraints_covering[idx]) {
                satisfied[covered_id] = true;
            }
        }
    }

    // Fill remaining available spots
    for (int idx : available_indices) {
        a[idx] = k + 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << (i == n ? "" : " ");
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

