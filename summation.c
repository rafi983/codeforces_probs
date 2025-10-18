#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    long long sum = 0;
    
    for (int i = 0; i < N; i++) {
        long long num;
        scanf("%lld", &num);
        sum += num;
    }
    
    
    if (sum < 0) {
        sum = -sum; 
    }
    
    printf("%lld\n", sum);
    
    return 0;
}
