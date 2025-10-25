#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }
    
    // Allocate and initialize frequency array
    int *freq = (int *)calloc((size_t)(m + 1), sizeof(int));
    if (!freq) {
        return 0;
    }
    
    // Read array and count frequencies
    for (int i = 0; i < n; ++i) {
        int num;
        if (scanf("%d", &num) != 1) {
            free(freq);
            return 0;
        }
        if (num >= 1 && num <= m) {
            freq[num]++;
        }
    }
    
    // Print the frequency of each number from 1 to m
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", freq[i]);
    }
    
    free(freq);
    return 0;
}
