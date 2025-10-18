#include <stdio.h>

int main() {
    int n;
    long long x; 
    scanf("%d %lld", &n, &x);
    
    long long packs = x;
    int distressed = 0;
    
    for (int i = 0; i < n; i++) {
        char sign;
        long long d;
        
        scanf(" %c %lld", &sign, &d);
        
        if (sign == '+') {
            packs += d;
        } else {
            if (packs >= d) {
                packs -= d;
            } else {
                distressed++;
            }
        }
    }
    
    printf("%lld %d\n", packs, distressed);
    return 0;
}
