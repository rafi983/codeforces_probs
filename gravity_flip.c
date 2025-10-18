#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int columns[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &columns[i]);
    }

    qsort(columns, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        printf("%d", columns[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
