#include <stdio.h>
#include <string.h>

int main() {
    char num1[101], num2[101];
    scanf("%s %s", num1, num2);
    
    int len = strlen(num1);
    
    // For each position, XOR the digits
    for (int i = 0; i < len; i++) {
        if (num1[i] != num2[i]) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    
    return 0;
}
