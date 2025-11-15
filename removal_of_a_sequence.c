#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }

    const long long limit = 1000000000000LL;

    while (t--) {
        long long x, y, k;
        if (scanf("%lld %lld %lld", &x, &y, &k) != 3) {
            return 0;
        }

        if (y == 1) {
            printf("-1\n");
            continue;
        }

        long long pos = k;
        int overflow = 0;

        for (long long i = 0; i < x && pos <= limit; i++) {
            long long add = (pos - 1) / (y - 1);
            if (pos > limit - add) {
                overflow = 1;
                break;
            }
            pos += add;
        }

        if (overflow || pos > limit) {
            printf("-1\n");
        } else {
            printf("%lld\n", pos);
        }
    }

    return 0;
}
