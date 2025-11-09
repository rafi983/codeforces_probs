#include <stdio.h>
#include <stdlib.h>

#define MAXN 200000
#define MAXM 200000
#define MAXE (2*MAXM + 5)

static int head[MAXN + 5];
static int to_[MAXE];
static int next_[MAXE];
static int edge_idx;

static int u_[MAXM + 5], v_[MAXM + 5];
static int color[MAXN + 5];

static void add_edge(int u, int v) {
    to_[edge_idx] = v; next_[edge_idx] = head[u]; head[u] = edge_idx++;
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; ++i) head[i] = -1;
    edge_idx = 0;

    for (int i = 1; i <= m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        u_[i] = u; v_[i] = v;
        add_edge(u, v);
        add_edge(v, u);
    }

    for (int i = 1; i <= n; ++i) color[i] = -1;

    int ok = 1;

    int *q = (int*)malloc(sizeof(int) * (n + 5));
    int qs = 0, qe = 0;

    for (int start = 1; start <= n && ok; ++start) {
        if (color[start] != -1) continue;
        color[start] = 0;
        qs = qe = 0; q[qe++] = start;
        while (qs < qe && ok) {
            int u = q[qs++];
            for (int ei = head[u]; ei != -1; ei = next_[ei]) {
                int v = to_[ei];
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q[qe++] = v;
                } else if (color[v] == color[u]) {
                    ok = 0; break;
                }
            }
        }
    }

    if (!ok) {
        puts("NO");
        free(q);
        return 0;
    }

    puts("YES");
    for (int i = 1; i <= m; ++i) {
        int u = u_[i], v = v_[i];
        if (color[u] == 0 && color[v] == 1) putchar('0');
        else if (color[u] == 1 && color[v] == 0) putchar('1');
        else {
            putchar('0');
        }
    }
    putchar('\n');
    free(q);
    return 0;
}

