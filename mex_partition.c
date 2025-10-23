#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int freq[101];
        memset(freq, 0, sizeof(freq));
        
        // Count frequency of each element
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            freq[x]++;
        }
        
        // Find the minimum frequency among elements starting from 0
        // until we find a missing element
        int min_freq = n + 1;
        int mex = 0;
        
        for (int i = 0; i <= 100; i++) {
            if (freq[i] == 0) {
                mex = i;
                break;
            }
            if (freq[i] < min_freq) {
                min_freq = freq[i];
            }
        }
        
        // The answer is the MEX of the original array
        // OR we can partition into min_freq groups where each has MEX = mex
        // The minimum score is the first index where frequency is 0
        printf("%d\n", mex);
    }
    
    return 0;
}
