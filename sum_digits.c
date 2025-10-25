#include <stdio.h>

int main(void) {
    int n;
    // Read the number of digits
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    char digit;
    int sum = 0;
    
    getchar();
    
    for (int i = 0; i < n; i++) {
        digit = getchar();
        if (digit >= '0' && digit <= '9') {
            sum += (digit - '0');  // Convert ASCII digit to integer value
        }
    }
    
    // Print the sum of digits
    printf("%d\n", sum);
    
    return 0;
}
