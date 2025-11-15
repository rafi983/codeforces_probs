#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) {
            return 0;
        }

        static long long a[200005];
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }

        static long long pref[200005];
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i];
        }

        long long bestB = -(1LL << 60);
        long long maxInc = 0;

        for (int r = 1; r <= n; r++) {
            long long Br = r - (long long)r * r + pref[r - 1];
            if (Br > bestB) {
                bestB = Br;
            }

            long long Ar = (long long)r * r + r - pref[r];
            long long inc = Ar + bestB;
            if (inc > maxInc) {
                maxInc = inc;
            }
        }

        long long total = pref[n] + (maxInc > 0 ? maxInc : 0);
        printf("%lld\n", total);
    }

    return 0;
}
