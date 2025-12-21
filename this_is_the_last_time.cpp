#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Casino {
    int l, r, val, id;
};

vector<int> coords;
vector<vector<int>> tree;
vector<bool> visited;
vector<Casino> casinos;

int get_coord(int val) {
    return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
}

void update(int node, int start, int end, int l, int r, int id) {
    if (l > end || r < start) return;
    if (l <= start && end <= r) {
        tree[node].push_back(id);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, id);
    update(node * 2 + 1, mid + 1, end, l, r, id);
}

void query(int node, int start, int end, int pos, queue<int>& q, int& max_coins) {
    // Process casinos at this node
    for (int id : tree[node]) {
        if (!visited[id]) {
            visited[id] = true;
            max_coins = max(max_coins, casinos[id].val);
            q.push(casinos[id].val);
        }
    }
    tree[node].clear(); // Clear processed casinos

    if (start == end) return;
    int mid = (start + end) / 2;
    if (pos <= mid) query(node * 2, start, mid, pos, q, max_coins);
    else query(node * 2 + 1, mid + 1, end, pos, q, max_coins);
}

void solve() {
    int n;
    int k;
    if (!(cin >> n >> k)) return;

    casinos.resize(n);
    coords.clear();
    coords.push_back(k);

    for (int i = 0; i < n; ++i) {
        cin >> casinos[i].l >> casinos[i].r >> casinos[i].val;
        casinos[i].id = i;
        coords.push_back(casinos[i].l);
        coords.push_back(casinos[i].r);
        coords.push_back(casinos[i].val);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    int m = coords.size();

    // Re-initialize tree
    tree.assign(4 * m + 1, vector<int>());

    for (int i = 0; i < n; ++i) {
        int l_idx = get_coord(casinos[i].l);
        int r_idx = get_coord(casinos[i].r);
        update(1, 1, m, l_idx, r_idx, i);
    }

    visited.assign(n, false);
    queue<int> q;
    q.push(k);

    int max_coins = k;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int pos = get_coord(curr);
        query(1, 1, m, pos, q, max_coins);
    }

    cout << max_coins << "\n";
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

