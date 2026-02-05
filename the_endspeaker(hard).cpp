#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

struct State {
    long long cost;
    int ways;
};

struct SegmentTree {
    int size;
    vector<State> tree;

    SegmentTree(int n) {
        size = 1;
        while (size <= n) size *= 2;
        tree.assign(2 * size, {INF, 0});
    }

    State merge(State a, State b) {
        if (a.cost < b.cost) return a;
        if (b.cost < a.cost) return b;
        if (a.cost == INF) return {INF, 0};
        return {a.cost, (int)((a.ways + (long long)b.ways) % MOD)};
    }

    void update(int x, State val) {
        int idx = x + size;
        tree[idx] = val;
        idx /= 2;
        while (idx > 0) {
            tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
            idx /= 2;
        }
    }

    State query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return {INF, 0};
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x, lx, m), query(l, r, 2 * x + 1, m, rx));
    }

    State query(int l, int r) {
        return query(l, r, 1, 0, size);
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<long long> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; ++i) P[i + 1] = P[i] + a[i];

    // prev_dp[i] stores {min_cost, ways} for suffix i starting with NEXT k (k+1)
    vector<State> prev_dp(n + 1, {INF, 0});

    // Base case: at index n (empty suffix), cost is 0, ways 1.
    prev_dp[n] = {0, 1};

    // Iterate k from m down to 1
    for (int k = m; k >= 1; --k) {
        SegmentTree st(n + 1);

        // Base case for current k at index n is also {0, 1}
        st.update(n, {0, 1});

        long long capacity = b[k - 1];
        long long cost_op = m - k;

        for (int i = n - 1; i >= 0; --i) {
            State res = {INF, 0};

            if (k < m) {
                State upgrade = prev_dp[i];
                res = upgrade;
            } else {
                // Type 1 impossible for k=m
            }

            long long target = P[i] + capacity;
            auto it = upper_bound(P.begin(), P.end(), target);
            int R = distance(P.begin(), it) - 1;

            if (R > i) {
                State best_next = st.query(i + 1, R + 1);

                if (best_next.cost != INF) {
                    State consume = {best_next.cost + cost_op, best_next.ways};

                    if (consume.cost < res.cost) {
                        res = consume;
                    } else if (consume.cost == res.cost) {
                        res.ways = (int)((res.ways + (long long)consume.ways) % MOD);
                    }
                }
            }

            st.update(i, res);

            prev_dp[i] = res;
        }
    }

    if (prev_dp[0].cost == INF) {
        cout << -1 << "\n";
    } else {
        cout << prev_dp[0].cost << " " << prev_dp[0].ways << "\n";
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
