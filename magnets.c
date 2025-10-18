#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int groups = 1;
    char prev_magnet[3];
    char current_magnet[3];

    scanf("%s", prev_magnet);

    for (int i = 1; i < n; i++) {
        scanf("%s", current_magnet);

        if (prev_magnet[1] == current_magnet[0]) {
            groups++;
        }
        strcpy(prev_magnet, current_magnet);
    }

    printf("%d\n", groups);

    return 0;
}
