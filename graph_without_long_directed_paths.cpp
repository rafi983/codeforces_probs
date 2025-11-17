#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 200000;
const int MAXM = 200000;
const int MAXE = 2 * MAXM + 5;

static int head[MAXN + 5];
static int to_[MAXE];
static int next_[MAXE];
static int edge_idx;

static int u_[MAXM + 5], v_[MAXM + 5];
static int color[MAXN + 5];

static void add_edge(int u, int v) {
    to_[edge_idx] = v;
    next_[edge_idx] = head[u];
    head[u] = edge_idx++;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; ++i) head[i] = -1;
    edge_idx = 0;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        u_[i] = u;
        v_[i] = v;
        add_edge(u, v);
        add_edge(v, u);
    }

    for (int i = 1; i <= n; ++i) color[i] = -1;

    bool ok = true;

    vector<int> q(n + 5);
    int qs = 0, qe = 0;

    for (int start = 1; start <= n && ok; ++start) {
        if (color[start] != -1) continue;
        color[start] = 0;
        qs = qe = 0;
        q[qe++] = start;

        while (qs < qe && ok) {
            int u = q[qs++];
            for (int ei = head[u]; ei != -1; ei = next_[ei]) {
                int v = to_[ei];
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q[qe++] = v;
                } else if (color[v] == color[u]) {
                    ok = false;
                    break;
                }
            }
        }
    }

    if (!ok) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= m; ++i) {
        int u = u_[i], v = v_[i];
        if (color[u] == 0 && color[v] == 1) {
            cout << '0';
        } else if (color[u] == 1 && color[v] == 0) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << endl;

    return 0;
}

