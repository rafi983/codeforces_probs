#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    while (t--) {
        int n;
        char s[55];
        scanf("%d", &n);
        scanf("%s", s);
        char grid[55][55];
        int twos[55];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '2') {
                twos[count++] = i;
            }
        }
        if (count == 1 || count == 2) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = (i == j) ? 'X' : '=';
            }
        }
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                int a = twos[i];
                int b = twos[(i + 1) % count];
                grid[a][b] = '+';
                grid[b][a] = '-';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                putchar(grid[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}