#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int x = 0;
    
    for (int i = 0; i < n; i++) {
        char statement[10];
        scanf("%s", statement);
        
        // Check if the statement contains "++" or "--"
        if (strstr(statement, "++") != NULL) {
            x++;
        } else if (strstr(statement, "--") != NULL) {
            x--;
        }
    }
    
    printf("%d\n", x);
    
    return 0;
}
