#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    long long int_a = *((long long *)a);
    long long int_b = *((long long *)b);

    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

int main() {
    long long s[4];
    int duplicates = 0;

    // Read the four horseshoe colors
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &s[i]);
    }

    // Sort the array to bring identical colors together
    qsort(s, 4, sizeof(long long), compare);

    // Count the number of duplicate colors
    for (int i = 0; i < 3; i++) {
        if (s[i] == s[i+1]) {
            duplicates++;
        }
    }

    // The number of horseshoes to buy is the number of duplicates
    printf("%d\n", duplicates);

    return 0;
}
