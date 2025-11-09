#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXN 100000
#define MAXE (2*MAXN + 5)

static int cat[MAXN + 5];
static int head[MAXN + 5];
static int to_[MAXE];
static int next_[MAXE];
static int deg_[MAXN + 5];
static int edge_idx = 0;

static void add_edge(int u, int v) {
    to_[edge_idx] = v; next_[edge_idx] = head[u]; head[u] = edge_idx++; deg_[u]++;
}

typedef struct { int node; int consec; int parent; } Frame;

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &cat[i]);

    for (int i = 1; i <= n; ++i) head[i] = -1, deg_[i] = 0;
    edge_idx = 0;

    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }

    Frame *stack = (Frame*)malloc(sizeof(Frame) * (n + 5));
    int top = 0;

    int start_consec = cat[1] ? 1 : 0;
    if (start_consec > m) {
        printf("0\n");
        free(stack);
        return 0;
    }

    stack[top++] = (Frame){1, start_consec, 0};

    int answer = 0;

    while (top) {
        Frame cur = stack[--top];
        int u = cur.node;
        int consec = cur.consec;
        int parent = cur.parent;

        int is_leaf = 1;
        for (int ei = head[u]; ei != -1; ei = next_[ei]) {
            int v = to_[ei];
            if (v == parent) continue;
            is_leaf = 0;
            int new_consec = cat[v] ? (consec + 1) : 0;
            if (new_consec > m) continue;
            stack[top++] = (Frame){v, new_consec, u};
        }
        if (is_leaf && u != 1) {
            answer++;
        }
    }

    printf("%d\n", answer);
    free(stack);
    return 0;
}

