#include <stdio.h>

int is_composite(int n) {
    if (n <= 3) return 0;  // 2 and 3 are prime
    if (n % 2 == 0) return 1;  // all even numbers > 2 are composite
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    
    if (n % 2 == 0) {
        if (is_composite(n/2)) {
            printf("%d %d\n", n/2, n/2);
        } else {
            printf("%d %d\n", n-8, 8);
        }
    } else {
        printf("%d %d\n", n-9, 9);
    }
    
    return 0;
}
