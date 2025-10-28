#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count[5] = {0};

    for (int i = 0; i < n; i++) {
        int s;
        scanf("%d", &s);
        count[s]++;
    }

    int taxis = 0;

    taxis += count[4];

    int pairs_3_1 = (count[3] < count[1]) ? count[3] : count[1];
    taxis += pairs_3_1;
    count[3] -= pairs_3_1;
    count[1] -= pairs_3_1;

    taxis += count[3];

    taxis += count[2] / 2;
    count[2] = count[2] % 2;

    if (count[2] > 0) {
        taxis++;
        if (count[1] >= 2) {
            count[1] -= 2;
        } else {
            count[1] = 0;
        }
    }

    taxis += (count[1] + 3) / 4;

    printf("%d\n", taxis);

    return 0;
}

