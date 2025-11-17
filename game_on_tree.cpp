#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 200000;
const int MAXE = 2 * MAXN;

static int head[MAXN + 5];
static int to_[MAXE + 5];
static int next_[MAXE + 5];
static int edge_idx = 0;
static int parent_[MAXN + 5];
static int grundy[MAXN + 5];
static int order[MAXN + 5];

static void add_edge(int u, int v) {
    to_[edge_idx] = v;
    next_[edge_idx] = head[u];
    head[u] = edge_idx++;
}

int main() {
    int n, t;
    if (!(cin >> n >> t)) return 0;

    for (int i = 1; i <= n; ++i) head[i] = -1;
    edge_idx = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    int start;
    if (!(cin >> start)) start = 1;

    int top = 0, oc = 0;
    parent_[start] = 0;
    order[oc++] = start;

    vector<int> stack(n + 5);
    stack[top++] = start;

    while (top) {
        int u = stack[--top];
        order[oc++] = u;
        for (int ei = head[u]; ei != -1; ei = next_[ei]) {
            int v = to_[ei];
            if (v == parent_[u]) continue;
            parent_[v] = u;
            stack[top++] = v;
        }
    }

    for (int idx = oc - 1; idx >= 0; --idx) {
        int u = order[idx];
        int child_count = 0;
        for (int ei = head[u]; ei != -1; ei = next_[ei]) {
            int v = to_[ei];
            if (v == parent_[u]) continue;
            child_count++;
        }

        if (child_count == 0) { // leaf
            grundy[u] = 0;
            continue;
        }

        int maxPossible = child_count;
        vector<bool> used(maxPossible + 2, false);

        for (int ei = head[u]; ei != -1; ei = next_[ei]) {
            int v = to_[ei];
            if (v == parent_[u]) continue;
            int g = grundy[v];
            if (g <= maxPossible) used[g] = true;
        }

        int mex = 0;
        while (mex <= maxPossible && used[mex]) mex++;
        grundy[u] = mex;
    }

    if (grundy[start] != 0) {
        cout << "Ron" << endl;
    } else {
        cout << "Hermione" << endl;
    }

    return 0;
}

