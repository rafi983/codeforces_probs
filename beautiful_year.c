#include <stdio.h>

int has_distinct_digits(int year) {
    int digits[10] = {0};
    
    while (year > 0) {
        int digit = year % 10;
        if (digits[digit] > 0) {
            return 0; 
        }
        digits[digit] = 1;
        year /= 10;
    }
    return 1;
}

int main() {
    int y;
    scanf("%d", &y);
    
    y++; 
    while (!has_distinct_digits(y)) {
        y++;
    }
    
    printf("%d\n", y);
    return 0;
}
