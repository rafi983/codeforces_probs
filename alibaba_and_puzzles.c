#include <stdio.h>

int main() {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    
    if (a + b - c == d) {
        printf("YES\n");
        return 0;
    }
    
    if (a + (b * c) == d) {
        printf("YES\n");
        return 0;
    }
    
    if (a - b + c == d) {
        printf("YES\n");
        return 0;
    }
    
    if (a - (b * c) == d) {
        printf("YES\n");
        return 0;
    }
    
    if ((a * b) + c == d) {
        printf("YES\n");
        return 0;
    }
    
    if ((a * b) - c == d) {
        printf("YES\n");
        return 0;
    }
    
    printf("NO\n");
    return 0;
}
