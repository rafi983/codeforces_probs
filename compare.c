#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[21];
    char str2[21];
    
    if (scanf("%s %s", str1, str2) != 2) {
        return 1;
    }
    
    int result = strcmp(str1, str2);
    
    if (result <= 0) {
        printf("%s\n", str1);
    } else {
        printf("%s\n", str2);
    }
    
    return 0;
}
