#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1)
        return 0;
    while (t--) {
        int n;
        scanf("%d", &n);
        int *a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int limit = n < 60 ? n : 60;
        int found = 0;
        int x = -1;
        int y = -1;
        for (int i = 0; i < limit && !found; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((a[j] % a[i]) % 2 == 0) {
                    x = a[i];
                    y = a[j];
                    found = 1;
                    break;
                }
            }
        }
        if (found)
            printf("%d %d\n", x, y);
        else
            printf("-1\n");
        free(a);
    }
    return 0;
}
