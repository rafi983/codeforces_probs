#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int is_colored = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char pixel;
            scanf(" %c", &pixel);
            if (pixel == 'C' || pixel == 'M' || pixel == 'Y') {
                is_colored = 1;
            }
        }
    }
    if (is_colored) {
        printf("#Color\n");
    } else {
        printf("#Black&White\n");
    }
    return 0;
}
