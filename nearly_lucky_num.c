#include <stdio.h>
#include <string.h>

int main() {
    char n[20];
    scanf("%s", n);
    
    // Count the number of lucky digits (4 and 7)
    int count = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        if (n[i] == '4' || n[i] == '7') {
            count++;
        }
    }
    
    if (count == 0) {
        printf("NO\n");
        return 0;
    }
    
    // Convert count to string and check if it contains only 4 and 7
    char count_str[20];
    sprintf(count_str, "%d", count);
    
    int is_lucky = 1;
    for (int i = 0; count_str[i] != '\0'; i++) {
        if (count_str[i] != '4' && count_str[i] != '7') {
            is_lucky = 0;
            break;
        }
    }
    
    if (is_lucky) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
