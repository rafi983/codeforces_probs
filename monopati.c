#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        int *top = (int*)malloc((n + 2) * sizeof(int));
        int *bot = (int*)malloc((n + 2) * sizeof(int));
        for (int i = 1; i <= n; ++i) scanf("%d", &top[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &bot[i]);

        int *prefMinTop = (int*)malloc((n + 2) * sizeof(int));
        int *prefMaxTop = (int*)malloc((n + 2) * sizeof(int));
        prefMinTop[1] = top[1]; prefMaxTop[1] = top[1];
        for (int i = 2; i <= n; ++i) {
            prefMinTop[i] = prefMinTop[i-1] < top[i] ? prefMinTop[i-1] : top[i];
            prefMaxTop[i] = prefMaxTop[i-1] > top[i] ? prefMaxTop[i-1] : top[i];
        }
        int *sufMinBot = (int*)malloc((n + 3) * sizeof(int));
        int *sufMaxBot = (int*)malloc((n + 3) * sizeof(int));
        const int INF = 1000000000;
        sufMinBot[n+1] = INF; // sentinel
        sufMaxBot[n+1] = 0;   // sentinel
        for (int i = n; i >= 1; --i) {
            int mn = bot[i];
            int mx = bot[i];
            if (sufMinBot[i+1] < mn) mn = sufMinBot[i+1];
            if (sufMaxBot[i+1] > mx) mx = sufMaxBot[i+1];
            sufMinBot[i] = mn;
            sufMaxBot[i] = mx;
        }

        // Collect A_k, B_k points
        int *bestB = (int*)malloc((2*n + 4) * sizeof(int));
        for (int v = 0; v <= 2*n + 3; ++v) bestB[v] = INF;
        for (int k = 1; k <= n; ++k) {
            int A = prefMinTop[k] < sufMinBot[k] ? prefMinTop[k] : sufMinBot[k];
            int B = prefMaxTop[k] > sufMaxBot[k] ? prefMaxTop[k] : sufMaxBot[k];
            if (bestB[A] > B) bestB[A] = B;
        }
        for (int L = 2*n; L >= 1; --L) {
            if (bestB[L] > bestB[L+1]) bestB[L] = bestB[L+1];
        }
        long long ans = 0;
        for (int l = 1; l <= 2*n; ++l) {
            int b = bestB[l];
            if (b >= INF) continue; // no point with A >= l
            int start = l;
            if (start < b) start = b; // need r >= b and r >= l
            if (start <= 2*n) {
                ans += (long long)(2*n - start + 1);
            }
        }
        printf("%lld\n", ans);

        free(top); free(bot);
        free(prefMinTop); free(prefMaxTop);
        free(sufMinBot); free(sufMaxBot);
        free(bestB);
    }
    return 0;
}

