#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Node {
    int max_p_open;
    int max_p_close;
};

vector<Node> tree;
int tree_size;

void init_tree(int n) {
    tree_size = 1;
    while (tree_size <= n) tree_size *= 2;
    tree.assign(2 * tree_size, {-INF, -INF});
}

void update(int idx, int p_open, int p_close) {
    if (idx < 0 || idx >= tree_size) return;
    int u = idx + tree_size;
    tree[u].max_p_open = max(tree[u].max_p_open, p_open);
    tree[u].max_p_close = max(tree[u].max_p_close, p_close);
    for (u /= 2; u >= 1; u /= 2) {
        tree[u].max_p_open = max(tree[2 * u].max_p_open, tree[2 * u + 1].max_p_open);
        tree[u].max_p_close = max(tree[2 * u].max_p_close, tree[2 * u + 1].max_p_close);
    }
}

int query_open(int l, int r) {
    l = max(0, l);
    r = min(r, tree_size - 1);
    if (l > r) return -INF;
    int res = -INF;
    for (l += tree_size, r += tree_size; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = max(res, tree[l++].max_p_open);
        if (r % 2 == 0) res = max(res, tree[r--].max_p_open);
    }
    return res;
}

int query_close(int l, int r) {
    l = max(0, l);
    r = min(r, tree_size - 1);
    if (l > r) return -INF;
    int res = -INF;
    for (l += tree_size, r += tree_size; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = max(res, tree[l++].max_p_close);
        if (r % 2 == 0) res = max(res, tree[r--].max_p_close);
    }
    return res;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    vector<int> bal(n);
    vector<int> p_open(n), p_close(n);

    int curr = 0;
    int open_cnt = 0;
    int close_cnt = 0;

    for(int i=0; i<n; ++i) {
        if(s[i] == '(') {
            curr++;
            open_cnt++;
        } else {
            curr--;
            close_cnt++;
        }
        bal[i] = curr;
        p_open[i] = open_cnt;
        p_close[i] = close_cnt;
    }

    vector<int> s_close(n + 1, 0);
    for(int i=n-1; i>=0; --i) {
        s_close[i] = s_close[i+1] + (s[i] == ')' ? 1 : 0);
    }

    init_tree(n + 1);

    int max_len = -1;

    for (int j = 0; j < n; ++j) {
        if (j > 0 && s[j-1] == ')') {
            int k = j - 1;
            int b = bal[k];
            update(b, p_open[k], p_close[k]);
        }

        if (s[j] == '(') {
            if (j == 0) continue;

            int limit = s_close[j+1] - 2;
            int b_val = bal[j-1];

            int upper_a = min(b_val - 1, limit);
            int best_open = query_open(0, upper_a);
            if (best_open != -INF) {
                int current_len = n - 2 * p_open[j-1] + 2 * best_open;
                if (current_len > max_len) max_len = current_len;
            }

            int lower_b = b_val;
            int upper_b = limit;
            int best_close = query_close(lower_b, upper_b);
            if (best_close != -INF) {
                int current_len = n - 2 * p_close[j-1] + 2 * best_close - 2;
                if (current_len > max_len) max_len = current_len;
            }
        }
    }

    cout << max_len << "\n";
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
