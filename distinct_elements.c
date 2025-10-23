#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        long long b[100005];
        int a[100005];
        
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &b[i]);
        }
        
        // For each position i, determine a[i]
        for (int i = 1; i <= n; i++) {
            long long diff;
            if (i == 1) {
                diff = b[1];
            } else {
                diff = b[i] - b[i-1];
            }
            
            // diff tells us the distance to the last occurrence
            // If diff == i, it's a new element
            // Otherwise, the last occurrence was at position i - diff
            
            int last_pos = i - diff;
            
            if (last_pos == 0) {
                // This is a new element, assign any value we haven't used
                // or just assign i
                a[i] = i;
            } else {
                // Copy the value from the last occurrence
                a[i] = a[last_pos];
            }
        }
        
        // Print the result
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]);
            if (i < n) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
