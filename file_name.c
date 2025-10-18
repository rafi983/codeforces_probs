#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char str[101];
    scanf("%s", str);
    
    int remove_count = 0;
    int i = 0;
    
    while (i <= n - 3) {
        if (str[i] == 'x' && str[i+1] == 'x' && str[i+2] == 'x') {
            remove_count++;
            i++;
        } else {
            i++;
        }
    }
    
    printf("%d\n", remove_count);
    return 0;
}
