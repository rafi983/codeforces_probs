#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;

    struct Node {
        long long val;
        int idx;
        long long lazy;
    };

    vector<Node> st;

    SegTree(int n): n(n), st(4 * n) {
        build(1, 1, n);
    }

    void build(int p, int l, int r) {
        st[p].lazy = 0;

        if (l == r) {
            st[p].val = l;
            st[p].idx = l;
            return;
        }

        int m = (l + r) / 2;
        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);
        pull(p);
    }

    void apply(int p, long long add) {
        st[p].val += add;
        st[p].lazy += add;
    }

    void push(int p) {
        if (st[p].lazy != 0) {
            apply(p * 2, st[p].lazy);
            apply(p * 2 + 1, st[p].lazy);
            st[p].lazy = 0;
        }
    }

    void pull(int p) {
        if (st[p * 2].val == st[p * 2 + 1].val) {
            st[p].val = st[p * 2].val;
            st[p].idx = min(st[p * 2].idx, st[p * 2 + 1].idx);
        } else if (st[p * 2].val > st[p * 2 + 1].val) {
            st[p].val = st[p * 2].val;
            st[p].idx = st[p * 2].idx;
        } else {
            st[p].val = st[p * 2 + 1].val;
            st[p].idx = st[p * 2 + 1].idx;
        }
    }

    void rangeAdd(int p, int l, int r, int ql, int qr, long long v) {
        if (ql > qr) return;

        if (ql <= l && r <= qr) {
            apply(p, v);
            return;
        }

        push(p);
        int m = (l + r) / 2;

        if (ql <= m) rangeAdd(p * 2, l, m, ql, qr, v);
        if (qr > m) rangeAdd(p * 2 + 1, m + 1, r, ql, qr, v);

        pull(p);
    }

    void rangeAdd(int l, int r, long long v) {
        rangeAdd(1, 1, n, l, r, v);
    }

    pair<long long, int> rangeMax(int p, int l, int r, int ql, int qr) {
        if (ql > qr) return {LLONG_MIN / 4, -1};

        if (ql <= l && r <= qr) return {st[p].val, st[p].idx};

        push(p);
        int m = (l + r) / 2;
        pair<long long, int> left = {LLONG_MIN / 4, -1};
        pair<long long, int> right = {LLONG_MIN / 4, -1};

        if (ql <= m) left = rangeMax(p * 2, l, m, ql, qr);
        if (qr > m) right = rangeMax(p * 2 + 1, m + 1, r, ql, qr);

        if (left.first > right.first) return left;
        if (right.first > left.first) return right;
        if (left.second == -1) return right;
        if (right.second == -1) return left;

        return {left.first, min(left.second, right.second)};
    }

    pair<long long, int> rangeMax(int ql, int qr) {
        return rangeMax(1, 1, n, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        vector<int> first(n + 1, -1), last(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            if (first[a[i]] == -1) first[a[i]] = i;
            last[a[i]] = i;
        }

        vector<vector<int>> adds(n + 2);
        for (int v = 1; v <= n; ++v) {
            if (last[v] != -1) {
                adds[last[v]].push_back(first[v]);
            }
        }

        SegTree stree(n);
        long long bestDelta = LLONG_MIN / 4;
        int bestL = 0, bestR = 0;

        for (int r = 1; r <= n; ++r) {
            for (int f : adds[r]) {
                if (f >= 1) stree.rangeAdd(1, f, 1);
            }

            auto mx = stree.rangeMax(1, r);
            long long V = mx.first;
            int lopt = mx.second;

            if (lopt < 1) lopt = 1;

            long long delta = V - (r + 1);

            if (delta > bestDelta || (delta == bestDelta && (r - lopt + 1) > (bestR - bestL + 1))) {
                bestDelta = delta;
                bestL = lopt;
                bestR = r;
            }
        }

        if (bestDelta < 0) {
            cout << 0 << '\n';
        } else {
            cout << bestL << ' ' << bestR << '\n';
        }
    }

    return 0;
}

