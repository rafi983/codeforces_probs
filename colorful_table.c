#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int *a = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int *head = (int*)malloc(sizeof(int)*(k+2));
        int *next = (int*)malloc(sizeof(int)*n);
        int *first_ge = (int*)malloc(sizeof(int)*(k+2));
        int *last_ge = (int*)malloc(sizeof(int)*(k+2));
        for (int i = 0; i <= k+1; ++i) head[i] = -1;
        for (int i = 0; i < n; ++i) { int v = a[i]; next[i] = head[v]; head[v] = i; }
        int current_min = n+1, current_max = 0;
        for (int c = k; c >= 1; --c) {
            for (int idx = head[c]; idx != -1; idx = next[idx]) {
                int pos = idx + 1;
                if (pos < current_min) current_min = pos;
                if (pos > current_max) current_max = pos;
            }
            first_ge[c] = current_min;
            last_ge[c] = current_max;
        }
        for (int c = 1; c <= k; ++c) {
            if (head[c] == -1) {
                printf("0%c", c==k?'\n':' ');
            } else {
                int width = last_ge[c] - first_ge[c] + 1;
                int ans = 2 * width;
                printf("%d%c", ans, c==k?'\n':' ');
            }
        }
        free(a); free(head); free(next); free(first_ge); free(last_ge);
    }
    return 0;
}
