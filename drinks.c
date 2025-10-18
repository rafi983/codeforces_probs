#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        sum += p;
    }
    
    // The average percentage is the sum divided by n
    double average = sum / n;
    
    printf("%.12f\n", average);
    
    return 0;
}
