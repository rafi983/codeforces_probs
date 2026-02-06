#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 200005;
const int LOGN = 19;

int a[MAXN];
int P[MAXN];
int MaxU[MAXN];
int st[MAXN][LOGN];
int logs[MAXN];

// Merge Sort Tree
vector<int> tree[4 * MAXN];

void build(int node, int start, int end) {
    tree[node].clear();
    if (start == end) {
        tree[node].push_back(P[start]);
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // Merge
        tree[node].reserve(tree[2 * node].size() + tree[2 * node + 1].size());
        merge(tree[2 * node].begin(), tree[2 * node].end(),
              tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              back_inserter(tree[node]));
    }
}

// Find max value in range [l, r] strictly less than val
int query_mst(int node, int start, int end, int l, int r, int val) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        // Binary search for largest element < val
        auto it = lower_bound(tree[node].begin(), tree[node].end(), val);
        if (it == tree[node].begin()) return 0;
        return *(--it);
    }
    int mid = (start + end) / 2;
    int p1 = query_mst(2 * node, start, mid, l, r, val);
    int p2 = query_mst(2 * node + 1, mid + 1, end, l, r, val);
    return max(p1, p2);
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    map<int, int> last_pos;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (last_pos.count(a[i])) {
            P[i] = last_pos[a[i]];
        } else {
            P[i] = 0;
        }
        last_pos[a[i]] = i;
    }

    build(1, 1, n);

    for (int i = 1; i <= n; ++i) {
        if (P[i] == 0) {
            MaxU[i] = 0;
        } else {
            // Check range (P[i] + 1, i - 1) for values < P[i]
            if (P[i] + 1 <= i - 1) {
                MaxU[i] = query_mst(1, 1, n, P[i] + 1, i - 1, P[i]);
            } else {
                MaxU[i] = 0;
            }
        }
    }

    // Build Sparse Table for RMQ on MaxU
    for (int i = 1; i <= n; ++i)
        st[i][0] = MaxU[i];

    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int k = 0; k < q; ++k) {
        int l, r;
        cin >> l >> r;
        // RMQ on MaxU[l...r]
        int len = r - l + 1;
        int lg = logs[len];
        int max_val = max(st[l][lg], st[r - (1 << lg) + 1][lg]);

        if (max_val >= l) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    logs[1] = 0;
    for (int i = 2; i < MAXN; i++)
        logs[i] = logs[i/2] + 1;

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
