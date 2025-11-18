#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

struct Edge {
    int to;
    int next;
};

static int *head = nullptr;
static Edge *edges = nullptr;
static int edge_cnt = 0;

static int *parent_arr = nullptr;
static int *sub = nullptr;
static int *stack_arr = nullptr;
static int *order = nullptr;

static void add_edge(int u, int v) {
    edges[edge_cnt].to = v;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int m2 = 2 * (n - 1);
        head = new int[n + 1];
        edges = new Edge[m2 + 5];
        parent_arr = new int[n + 1];
        sub = new int[n + 1];
        stack_arr = new int[n + 5];
        order = new int[n + 5];

        for (int i = 1; i <= n; ++i) head[i] = -1;
        edge_cnt = 0;

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
            add_edge(v, u);
        }

        int top = 0, ord_sz = 0;
        stack_arr[top++] = 1;
        parent_arr[1] = 0;
        for (int i = 2; i <= n; ++i) parent_arr[i] = -1;

        while (top) {
            int v = stack_arr[--top];
            order[ord_sz++] = v;
            for (int e = head[v]; e != -1; e = edges[e].next) {
                int u = edges[e].to;
                if (u == parent_arr[v]) continue;
                if (parent_arr[u] != -1) continue;
                parent_arr[u] = v;
                stack_arr[top++] = u;
            }
        }

        for (int i = 1; i <= n; ++i) sub[i] = 1;
        for (int i = ord_sz - 1; i >= 0; --i) {
            int v = order[i];
            int p = parent_arr[v];
            if (p > 0) sub[p] += sub[v];
        }

        ll ans = 0;
        for (int v = 1; v <= n; ++v) {
            ll cnt_v = (n >= k) ? 1 : 0;
            for (int e = head[v]; e != -1; e = edges[e].next) {
                int u = edges[e].to;
                int a;
                int n_minus_a;
                if (parent_arr[v] == u) {
                    a = sub[v];
                    n_minus_a = n - a;
                } else if (parent_arr[u] == v) {
                    a = n - sub[u];
                    n_minus_a = sub[u];
                } else {
                    continue;
                }
                if (a >= k) cnt_v += n_minus_a;
            }
            ans += cnt_v;
        }

        cout << ans << endl;

        delete[] head; head = nullptr;
        delete[] edges; edges = nullptr;
        delete[] parent_arr; parent_arr = nullptr;
        delete[] sub; sub = nullptr;
        delete[] stack_arr; stack_arr = nullptr;
        delete[] order; order = nullptr;
    }

    return 0;
}

