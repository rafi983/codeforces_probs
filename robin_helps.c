#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int robin_gold = 0;
        int people_helped = 0;

        for (int i = 0; i < n; i++) {
            int ai;
            scanf("%d", &ai);

            if (ai >= k) {
                robin_gold += ai;
            } else if (ai == 0) {
                if (robin_gold > 0) {
                    robin_gold--;
                    people_helped++;
                }
            }
        }

        printf("%d\n", people_helped);
    }

    return 0;
}

