#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long x;
        scanf("%lld", &x);
        
        long long path[100];
        int len = 0;
        long long val = x;
        
        while (val > 0) {
            path[len++] = val;
            val = val / 2;
        }
        
        for (int i = 0; i < len / 2; i++) {
            long long temp = path[i];
            path[i] = path[len - 1 - i];
            path[len - 1 - i] = temp;
        }
        
        
        long long actions = 2 * len + 1;
        
        printf("%lld\n", actions);
    }
    
    return 0;
}
