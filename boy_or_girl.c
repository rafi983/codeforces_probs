#include <stdio.h>
#include <string.h>

int main() {
    char username[101];
    scanf("%s", username);
    
    int char_present[26] = {0};  // 26 lowercase letters
    
    for (int i = 0; username[i] != '\0'; i++) {
        char_present[username[i] - 'a'] = 1;
    }
    
    int distinct_count = 0;
    for (int i = 0; i < 26; i++) {
        if (char_present[i]) {
            distinct_count++;
        }
    }
    
    if (distinct_count % 2 == 1) {
        printf("IGNORE HIM!\n");
    } else {
        printf("CHAT WITH HER!\n");
    }
    
    return 0;
}
