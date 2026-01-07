#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e16;

struct Node {
    long long sum;
    long long max_L;
    long long max_R;
    long long max_single;
    long long max_double;
    long long max_single_plus_L;
    long long max_R_plus_single;
    long long max_R_plus_L;

    Node() {
        sum = 0;
        max_L = -INF;
        max_R = -INF;
        max_single = -INF;
        max_double = -INF;
        max_single_plus_L = -INF;
        max_R_plus_single = -INF;
        max_R_plus_L = -INF;
    }
};

Node merge(const Node& l, const Node& r) {
    if (l.max_single == -INF && l.sum == 0 && l.max_L == -INF) return r; // Approximate check for identity
    if (r.max_single == -INF && r.sum == 0 && r.max_L == -INF) return l;

    Node res;
    res.sum = l.sum + r.sum;

    res.max_L = max(r.max_L, l.max_L + r.sum);
    res.max_R = max(l.max_R, l.sum + r.max_R);

    // max_single
    res.max_single = max({l.max_single, r.max_single, l.max_L + r.max_R});

    // max_R_plus_L (Prefix + Suffix)
    res.max_R_plus_L = max({
        l.max_R_plus_L + r.sum,
        l.max_R + r.max_L,
        l.sum + r.max_R_plus_L
    });

    // max_single_plus_L (Interval + Suffix)
    res.max_single_plus_L = max({
        l.max_single_plus_L + r.sum, // Both in L
        l.max_single + r.max_L,      // I in L, Suff in R
        l.max_L + r.max_R_plus_L,    // I crossing
        r.max_single_plus_L          // Both in R
    });

    // max_R_plus_single (Prefix + Interval)
    res.max_R_plus_single = max({
        l.max_R_plus_single,         // Both in L
        l.max_R + r.max_single,      // Pref in L, I in R
        l.max_R_plus_L + r.max_R,    // I crossing
        l.sum + r.max_R_plus_single  // Both in R
    });

    // max_double
    res.max_double = max({
        l.max_double,
        r.max_double,
        l.max_single + r.max_single,
        l.max_single_plus_L + r.max_R,
        l.max_L + r.max_R_plus_single
    });

    return res;
}

int n;
vector<long long> a, b;
vector<Node> tree;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].sum = a[start];
        tree[node].max_L = a[start] + b[start];
        tree[node].max_R = a[start] + b[start];
        tree[node].max_single = a[start] + 2LL * b[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void update_a(int node, int start, int end, int idx, int val) {
    if (start == end) {
        a[idx] = val;
        tree[node].sum = a[idx];
        tree[node].max_L = a[idx] + b[idx];
        tree[node].max_R = a[idx] + b[idx];
        tree[node].max_single = a[idx] + 2LL * b[idx];
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update_a(2 * node, start, mid, idx, val);
    else update_a(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void update_b(int node, int start, int end, int idx, int val) {
    if (start == end) {
        b[idx] = val;
        tree[node].max_L = a[idx] + b[idx];
        tree[node].max_R = a[idx] + b[idx];
        tree[node].max_single = a[idx] + 2LL * b[idx];
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update_b(2 * node, start, mid, idx, val);
    else update_b(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return Node();
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    if (r <= mid) return query(2 * node, start, mid, l, r);
    if (l > mid) return query(2 * node + 1, mid + 1, end, l, r);

    return merge(
        query(2 * node, start, mid, l, r),
        query(2 * node + 1, mid + 1, end, l, r)
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    a.resize(n + 1);
    b.resize(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    tree.resize(4 * n + 1);
    build(1, 1, n);

    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            update_a(1, 1, n, p, x);
        } else if (type == 2) {
            int p, x;
            cin >> p >> x;
            update_b(1, 1, n, p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r).max_double << "\n";
        }
    }

    return 0;
}

