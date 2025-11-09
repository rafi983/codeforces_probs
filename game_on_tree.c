#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200000
#define MAXE (2*MAXN)

static int head[MAXN + 5];
static int to_[MAXE + 5];
static int next_[MAXE + 5];
static int edge_idx = 0;
static int parent_[MAXN + 5];
static int grundy[MAXN + 5];
static int order[MAXN + 5];

static void add_edge(int u, int v) {
    to_[edge_idx] = v; next_[edge_idx] = head[u]; head[u] = edge_idx++;
}

int main(void) {
    int n, t;
    if (scanf("%d %d", &n, &t) != 2) return 0;
    for (int i = 1; i <= n; ++i) head[i] = -1; edge_idx = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        add_edge(u, v); add_edge(v, u);
    }
    int start;
    if (scanf("%d", &start) != 1) start = 1;

    int top = 0, oc = 0;
    parent_[start] = 0;
    order[oc++] = start;
    int *stack = (int*)malloc(sizeof(int) * (n + 5));
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
    free(stack);

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
        unsigned char used[maxPossible + 2];
        for (int i = 0; i <= maxPossible + 1; ++i) used[i] = 0;
        for (int ei = head[u]; ei != -1; ei = next_[ei]) {
            int v = to_[ei];
            if (v == parent_[u]) continue;
            int g = grundy[v];
            if (g <= maxPossible) used[g] = 1;
        }
        int mex = 0;
        while (mex <= maxPossible && used[mex]) mex++;
        grundy[u] = mex;
    }

    if (grundy[start] != 0) {
        puts("Ron");
    } else {
        puts("Hermione");
    }
    return 0;
}

