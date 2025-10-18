#include <stdio.h>

#define MOD (1LL << 30)

int main(void) {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 0;
    }

    int max_val = a * b * c;
    int *divisors = (int *)malloc((size_t)(max_val + 1) * sizeof(int));
    if (!divisors) {
        return 0;
    }

    for (int i = 0; i <= max_val; ++i) {
        divisors[i] = 0;
    }

    for (int i = 1; i <= max_val; ++i) {
        for (int j = i; j <= max_val; j += i) {
            ++divisors[j];
        }
    }

    long long sum = 0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                sum += divisors[i * j * k];
            }
        }
    }

    printf("%lld\n", sum % MOD);

    free(divisors);
    return 0;
}
