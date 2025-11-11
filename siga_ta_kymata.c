#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        int *p = (int*)malloc((size_t)(n + 1) * sizeof(int));
        int pos1 = -1, posn = -1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i]);
            if (p[i] == 1) pos1 = i;
            if (p[i] == n) posn = i;
        }
        char *x = (char*)malloc((size_t)(n + 5) * sizeof(char));
        scanf("%s", x);

        int impossible = 0;
        if (x[0] == '1' || x[n-1] == '1' || x[pos1-1] == '1' || x[posn-1] == '1') {
            impossible = 1;
        }

        if (impossible) {
            printf("-1\n");
            free(p); free(x);
            continue;
        }

        int ops[5][2];
        int k = 0;

        k = 0;
        int l, r;
        l = pos1; r = posn; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = 1; r = pos1; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = 1; r = posn; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = pos1; r = n; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;
        l = posn; r = n; if (l > r) { int tmp = l; l = r; r = tmp; } ops[k][0] = l; ops[k][1] = r; k++;

        printf("%d\n", k);
        for (int i = 0; i < k; ++i) {
            printf("%d %d\n", ops[i][0], ops[i][1]);
        }

        free(p);
        free(x);
    }
    return 0;
}

