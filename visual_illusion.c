#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        int size = 2 * n + 1;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int d = abs(i - n) + abs(j - n);
                putchar((d % 3 == 0) ? 'b' : 'w');
            }
            putchar('\n');
        }
    }
    return 0;
}

