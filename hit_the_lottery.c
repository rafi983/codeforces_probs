#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    
    long long bills = 0;
    
    
    bills += n / 100;
    n %= 100;
    
    bills += n / 20;
    n %= 20;
    
    bills += n / 10;
    n %= 10;
    
    bills += n / 5;
    n %= 5;
    
    bills += n;
    
    printf("%lld\n", bills);
    
    return 0;
}
