#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct User {
    int l, r, id;
};

bool compareUsers(const User& a, const User& b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.r > b.r;
}

class FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] = max(tree[idx], val);
        }
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res = max(res, tree[idx]);
        }
        return res;
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<User> users(n);
    vector<long long> answers(n);
    map<pair<int, int>, int> counts;
    vector<int> unique_r;

    for (int i = 0; i < n; ++i) {
        cin >> users[i].l >> users[i].r;
        users[i].id = i;
        counts[{users[i].l, users[i].r}]++;
        unique_r.push_back(users[i].r);
    }

    // Coordinate compression for R values
    sort(unique_r.begin(), unique_r.end());
    unique_r.erase(unique(unique_r.begin(), unique_r.end()), unique_r.end());

    auto get_r_rank = [&](int r) {
        // Find index in unique_r
        return lower_bound(unique_r.begin(), unique_r.end(), r) - unique_r.begin();
    };

    // Sort users for processing
    sort(users.begin(), users.end(), compareUsers);

    int bit_size = unique_r.size();
    FenwickTree ft(bit_size);

    // Multiset for finding min R >= current R
    multiset<int> active_rs;

    for (const auto& u : users) {


        if (counts[{u.l, u.r}] > 1) {
            answers[u.id] = 0;
            // Still add to structure
            active_rs.insert(u.r);
            int rank = get_r_rank(u.r);
            int bit_idx = bit_size - rank; // transform to reverse rank
            ft.update(bit_idx, u.l);
            continue;
        }

        auto it = active_rs.lower_bound(u.r);
        if (it == active_rs.end()) {
            // No predictor with R >= current R
            answers[u.id] = 0;
        } else {
            int min_r = *it;

            int rank = get_r_rank(u.r);
            int bit_idx = bit_size - rank;
            int max_l = ft.query(bit_idx);

            long long count = (long long)(min_r - max_l + 1) - (long long)(u.r - u.l + 1);
            answers[u.id] = max(0LL, count);
        }

        // Add current to structure
        active_rs.insert(u.r);
        int rank = get_r_rank(u.r);
        int bit_idx = bit_size - rank;
        ft.update(bit_idx, u.l);
    }

    for (int i = 0; i < n; ++i) {
        cout << answers[i] << "\n";
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

