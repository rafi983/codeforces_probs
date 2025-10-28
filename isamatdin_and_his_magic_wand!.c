#include <stdio.h>
#include <stdlib.h>

static int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        long long *a = (long long*)malloc(sizeof(long long) * n);
        if (!a) return 0;
        int hasOdd = 0, hasEven = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            if (a[i] & 1LL) hasOdd = 1; else hasEven = 1;
        }
        if (hasOdd && hasEven) {
            qsort(a, n, sizeof(long long), cmp_ll);
        }
        for (int i = 0; i < n; ++i) {
            if (i) putchar(' ');
            printf("%lld", a[i]);
        }
        putchar('\n');
        free(a);
    }
    return 0;
}

