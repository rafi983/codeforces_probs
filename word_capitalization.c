#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[1001];
    scanf("%s", word);
    
    // Capitalize the first letter if it's lowercase
    if (word[0] >= 'a' && word[0] <= 'z') {
        word[0] = word[0] - 'a' + 'A';
    }
    
    printf("%s\n", word);
    
    return 0;
}
