#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef long long ll;

typedef struct { int to; int next; } Edge;

static int *head = NULL;
static Edge *edges = NULL;
static int edge_cnt = 0;

static int *parent_arr = NULL;
static int *sub = NULL;
static int *stack_arr = NULL;
static int *order = NULL;

static void add_edge(int u, int v) {
    edges[edge_cnt].to = v;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt++;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, k;
        if (scanf("%d %d", &n, &k) != 2) return 0;

        int m2 = 2 * (n - 1);
        head = (int*)malloc((n + 1) * sizeof(int));
        edges = (Edge*)malloc((m2 + 5) * sizeof(Edge));
        parent_arr = (int*)malloc((n + 1) * sizeof(int));
        sub = (int*)malloc((n + 1) * sizeof(int));
        stack_arr = (int*)malloc((n + 5) * sizeof(int));
        order = (int*)malloc((n + 5) * sizeof(int));
        if (!head || !edges || !parent_arr || !sub || !stack_arr || !order) {
            fprintf(stderr, "Memory allocation failed\n");
            return 0;
        }

        for (int i = 1; i <= n; ++i) head[i] = -1;
        edge_cnt = 0;

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
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

        printf("%lld\n", ans);

        free(head); head = NULL;
        free(edges); edges = NULL;
        free(parent_arr); parent_arr = NULL;
        free(sub); sub = NULL;
        free(stack_arr); stack_arr = NULL;
        free(order); order = NULL;
    }

    return 0;
}

