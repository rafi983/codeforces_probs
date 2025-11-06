#include <stdio.h>

int main(void) {
    int a[5];
    long long sum = 0;
    for (int i = 0; i < 5; ++i) {
        if (scanf("%d", &a[i]) != 1) return 0;
        sum += a[i];
    }

    int cnt[101] = {0};
    for (int i = 0; i < 5; ++i) {
        if (a[i] >= 1 && a[i] <= 100) cnt[a[i]]++;
    }

    int best = 0;
    for (int v = 1; v <= 100; ++v) {
        if (cnt[v] >= 2) {
            int take = (cnt[v] >= 3) ? 3 : 2;
            int reduction = v * take;
            if (reduction > best) best = reduction;
        }
    }

    printf("%lld\n", sum - best);
    return 0;
}

