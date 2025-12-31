#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long max_val1; // max(a[i] - i)
    long long min_val1; // min(a[i] - i)
    long long ans1;     // max((a[i] - i) - (a[j] - j)) for i >= j

    long long max_val2; // max(a[i] + i)
    long long min_val2; // min(a[i] + i)
    long long ans2;     // max((a[i] + i) - (a[j] + j)) for i <= j
};

Node merge(const Node& l, const Node& r) {
    Node res;
    res.max_val1 = max(l.max_val1, r.max_val1);
    res.min_val1 = min(l.min_val1, r.min_val1);
    res.ans1 = max({l.ans1, r.ans1, r.max_val1 - l.min_val1});

    res.max_val2 = max(l.max_val2, r.max_val2);
    res.min_val2 = min(l.min_val2, r.min_val2);
    res.ans2 = max({l.ans2, r.ans2, l.max_val2 - r.min_val2});
    return res;
}

vector<long long> a;
vector<Node> tree;
int n;

void build(int node, int start, int end) {
    if (start == end) {
        long long val = a[start - 1];
        tree[node].max_val1 = val - start;
        tree[node].min_val1 = val - start;
        tree[node].ans1 = 0;
        tree[node].max_val2 = val + start;
        tree[node].min_val2 = val + start;
        tree[node].ans2 = 0;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node].max_val1 = (long long)val - start;
        tree[node].min_val1 = (long long)val - start;
        tree[node].ans1 = 0;
        tree[node].max_val2 = (long long)val + start;
        tree[node].min_val2 = (long long)val + start;
        tree[node].ans2 = 0;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

void solve() {
    int q;
    if (!(cin >> n >> q)) return;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    tree.resize(4 * n + 1);
    build(1, 1, n);

    cout << max(tree[1].ans1, tree[1].ans2) << "\n";

    while (q--) {
        int p, x;
        cin >> p >> x;
        update(1, 1, n, p, x);
        cout << max(tree[1].ans1, tree[1].ans2) << "\n";
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

