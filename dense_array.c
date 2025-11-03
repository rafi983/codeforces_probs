#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int a[50];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int totalInsertions = 0;

        for (int i = 0; i < n - 1; i++) {
            int smaller = a[i] < a[i + 1] ? a[i] : a[i + 1];
            int larger = a[i] > a[i + 1] ? a[i] : a[i + 1];

            int insertions = 0;
            while (larger > smaller * 2) {
                smaller *= 2;
                insertions++;
            }

            totalInsertions += insertions;
        }

        printf("%d\n", totalInsertions);
    }

    return 0;
}

