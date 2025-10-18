#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int welfare[100];  // Array to store welfare values
    int max_welfare = 0;  // Track maximum welfare
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &welfare[i]);
        if (welfare[i] > max_welfare) {
            max_welfare = welfare[i];
        }
    }
    
    long long total_burles = 0;
    for (int i = 0; i < n; i++) {
        total_burles += max_welfare - welfare[i];
    }
    
    printf("%lld\n", total_burles);
    
    return 0;
}
