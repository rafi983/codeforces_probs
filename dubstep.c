#include <stdio.h>
#include <string.h>

int main() {
    char remix[201];
    scanf("%s", remix);
    
    int len = strlen(remix);
    int i = 0;
    int first_word = 1;  
    
    while (i < len) {
        
        if (i + 2 < len && remix[i] == 'W' && remix[i+1] == 'U' && remix[i+2] == 'B') {
            i += 3;  
        } else {
            
            if (!first_word) {
                printf(" ");
            }
            
        
            while (i < len && 
                   !(i + 2 < len && remix[i] == 'W' && remix[i+1] == 'U' && remix[i+2] == 'B')) {
                printf("%c", remix[i]);
                i++;
            }
            
            first_word = 0;
        }
    }
    
    printf("\n");
    return 0;
}
