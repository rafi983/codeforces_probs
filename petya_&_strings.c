#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[101], s2[101];
    scanf("%s %s", s1, s2);
    
    int len = strlen(s1);
    
    int result = 0;
    
    for (int i = 0; i < len; i++) {
        // Convert both characters to lowercase for comparison
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);
        
        if (c1 < c2) {
            result = -1;
            break;
        } else if (c1 > c2) {
            result = 1;
            break;
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}
