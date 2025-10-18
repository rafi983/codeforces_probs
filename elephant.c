#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    
    int steps = (x + 4) / 5;  // This is ceiling division: (x + 5 - 1) / 5
    
    printf("%d\n", steps);
    
    return 0;
}
