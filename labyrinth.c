#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int traps = 0;
    for (int i = 0; i < n; i++) {
        char row[m + 1];
        scanf("%s", row);
        for (int j = 0; j < m; j++) {
            if (row[j] == 'x') {
                traps++;
            }
        }
    }
    printf("%d\n", traps);
    return 0;
}

