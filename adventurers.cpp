#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, id;
};

struct SegTree {
    vector<int> tree;
    int size_n;

    SegTree(int sz) : size_n(sz), tree(4 * sz, 0) {}

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query_kth(int node, int start, int end, int k) {
        if (start == end) return start;
        int mid = (start + end) / 2;
        if (tree[2 * node] >= k) return query_kth(2 * node, start, mid, k);
        else return query_kth(2 * node + 1, mid + 1, end, k - tree[2 * node]);
    }

    int count() {
        return tree[1];
    }

    void add(int idx, int val) {
        update(1, 0, size_n - 1, idx, val);
    }

    int get_kth(int k) {
        if (k > tree[1] || k <= 0) return -1;
        return query_kth(1, 0, size_n - 1, k);
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<Point> pts(n);
    vector<int> ys;
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].id = i;
        ys.push_back(pts[i].y);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto get_y_idx = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
    };

    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    int m = ys.size();
    SegTree L(m), R(m);

    for (const auto& p : pts) {
        R.add(get_y_idx(p.y), 1);
    }

    int best_k = 0;
    int best_x = pts[n/2].x;
    int best_y = pts[n/2].y;

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && pts[j].x == pts[i].x) {
            j++;
        }
        for (int k = i; k < j; ++k) {
            int y_idx = get_y_idx(pts[k].y);
            R.add(y_idx, -1);
            L.add(y_idx, 1);
        }

        int sizeL = L.count();
        int sizeR = R.count();

        if (min(sizeL, sizeR) / 2 > best_k) {
            int low = best_k + 1, high = min(sizeL, sizeR) / 2;
            int current_found_k = -1;
            int found_y = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int l_k_idx = L.get_kth(mid);
                int l_top_idx = L.get_kth(sizeL - mid + 1);

                int r_k_idx = R.get_kth(mid);
                int r_top_idx = R.get_kth(sizeR - mid + 1);

                int val_l_k = ys[l_k_idx];
                int val_l_top = ys[l_top_idx];
                int val_r_k = ys[r_k_idx];
                int val_r_top = ys[r_top_idx];

                int min_bound = max(val_l_k, val_r_k);
                int max_bound = min(val_l_top, val_r_top);

                if (min_bound < max_bound) {
                    current_found_k = mid;
                    found_y = max_bound;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (current_found_k > best_k) {
                best_k = current_found_k;
                best_x = pts[i].x + 1;
                best_y = found_y;
            }
        }
        i = j;
    }

    cout << best_k << "\n";
    cout << best_x << " " << best_y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) solve();
    }
    return 0;
}

