#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000;
const int MAXE = 2 * MAXN + 5;

static int cat[MAXN + 5];
static int head[MAXN + 5];
static int to_[MAXE];
static int next_[MAXE];
static int deg_[MAXN + 5];
static int edge_idx = 0;

static void add_edge(int u, int v) {
    to_[edge_idx] = v;
    next_[edge_idx] = head[u];
    head[u] = edge_idx++;
    deg_[u]++;
}

struct Frame {
    int node;
    int consec;
    int parent;
};

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; ++i) {
        cin >> cat[i];
    }

    for (int i = 1; i <= n; ++i) {
        head[i] = -1;
        deg_[i] = 0;
    }
    edge_idx = 0;

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }

    vector<Frame> stack(n + 5);
    int top = 0;

    int start_consec = cat[1] ? 1 : 0;
    if (start_consec > m) {
        cout << "0" << endl;
        return 0;
    }

    stack[top++] = {1, start_consec, 0};

    int answer = 0;

    while (top) {
        Frame cur = stack[--top];
        int u = cur.node;
        int consec = cur.consec;
        int parent = cur.parent;

        bool is_leaf = true;
        for (int ei = head[u]; ei != -1; ei = next_[ei]) {
            int v = to_[ei];
            if (v == parent) continue;
            is_leaf = false;
            int new_consec = cat[v] ? (consec + 1) : 0;
            if (new_consec > m) continue;
            stack[top++] = {v, new_consec, u};
        }
        if (is_leaf && u != 1) {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}

