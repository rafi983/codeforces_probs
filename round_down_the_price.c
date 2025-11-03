#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long m;
        scanf("%lld", &m);

        long long power = 1;
        long long temp = m;

        while (temp >= 10) {
            temp /= 10;
            power *= 10;
        }

        printf("%lld\n", m - power);
    }

    return 0;
}

