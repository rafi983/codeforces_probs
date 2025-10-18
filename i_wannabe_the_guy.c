#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int levels[101] = {0}; // Levels are 1-100
    int p, level_index;

    // Read Little X's levels
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &level_index);
        levels[level_index] = 1;
    }

    // Read Little Y's levels
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &level_index);
        levels[level_index] = 1;
    }

    // Check if all levels are covered
    int all_levels_passed = 1;
    for (int i = 1; i <= n; i++) {
        if (levels[i] == 0) {
            all_levels_passed = 0;
            break;
        }
    }

    if (all_levels_passed) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }

    return 0;
}
