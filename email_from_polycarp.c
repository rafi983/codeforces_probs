#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        char s[1000001], t[1000001];
        scanf("%s %s", s, t);
        
        int len_s = strlen(s);
        int len_t = strlen(t);
        
        int i = 0, j = 0;
        int valid = 1;
        
        while (i < len_s && j < len_t) {
            // If characters don't match, it's impossible
            if (s[i] != t[j]) {
                valid = 0;
                break;
            }
            
            char current_char = s[i];
            int count_s = 0, count_t = 0;
            
            // Count consecutive occurrences in s
            while (i < len_s && s[i] == current_char) {
                count_s++;
                i++;
            }
            
            // Count consecutive occurrences in t
            while (j < len_t && t[j] == current_char) {
                count_t++;
                j++;
            }
            
            // t must have at least as many characters as s
            if (count_t < count_s) {
                valid = 0;
                break;
            }
        }
        
        // Check if we consumed both strings completely
        if (i != len_s || j != len_t) {
            valid = 0;
        }
        
        printf("%s\n", valid ? "YES" : "NO");
    }
    
    return 0;
}
