#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int p[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }

        int found = 0;
        int i, j, k;

        for (j = 1; j < n - 1; j++) {
            int foundI = -1;
            int foundK = -1;

            for (int x = 0; x < j; x++) {
                if (p[x] < p[j]) {
                    foundI = x;
                    break;
                }
            }

            for (int x = j + 1; x < n; x++) {
                if (p[x] < p[j]) {
                    foundK = x;
                    break;
                }
            }

            if (foundI != -1 && foundK != -1) {
                i = foundI;
                k = foundK;
                found = 1;
                break;
            }
        }

        if (found) {
            printf("YES\n");
            printf("%d %d %d\n", i + 1, j + 1, k + 1);
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

