#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

int main(void) {
    int t;
    char word[MAX_LEN];
    
    if (scanf("%d", &t) != 1) {
        return 1;
    }
    
    for (int i = 0; i < t; i++) {
        if (scanf("%s", word) != 1) {
            return 1;
        }
        
        int length = strlen(word);
        
        if (length > 10) {
            printf("%c%d%c\n", word[0], length - 2, word[length - 1]);
        } else {
            printf("%s\n", word);
        }
    }
    
    return 0;
}
