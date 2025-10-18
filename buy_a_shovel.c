#include <stdio.h>

int main() {
    int k, r;
    scanf("%d %d", &k, &r);

    int count = 1;
    while (1) {
        long long total_cost = (long long)count * k;
        if (total_cost % 10 == 0 || total_cost % 10 == r) {
            printf("%d\n", count);
            break;
        }
        count++;
    }

    return 0;
}
