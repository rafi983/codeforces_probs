#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int coins[100];
    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
        totalSum += coins[i];
    }

    qsort(coins, n, sizeof(int), compare);

    int mySum = 0;
    int coinsCount = 0;

    for (int i = 0; i < n; i++) {
        mySum += coins[i];
        coinsCount++;

        int twinSum = totalSum - mySum;
        if (mySum > twinSum) {
            break;
        }
    }

    printf("%d\n", coinsCount);

    return 0;
}

