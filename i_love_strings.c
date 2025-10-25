#include <stdio.h>
#include <string.h>

#define MAX_LEN 51

int main(void) {
    int n;
    char s[MAX_LEN], t[MAX_LEN];
    
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        if (scanf("%s %s", s, t) != 2) {
            return 1;
        }
        
        int len_s = strlen(s);
        int len_t = strlen(t);
        int max_len = (len_s > len_t) ? len_s : len_t;
        
        for (int j = 0; j < max_len; j++) {
            if (j < len_s) {
                putchar(s[j]);
            }
            
            if (j < len_t) {
                putchar(t[j]);
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}
