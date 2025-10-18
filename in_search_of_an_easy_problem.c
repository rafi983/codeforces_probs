#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int is_hard = 0;
    for (int i = 0; i < n; i++) {
        int opinion;
        scanf("%d", &opinion);
        if (opinion == 1) {
            is_hard = 1;
        }
    }
    
    if (is_hard) {
        printf("HARD\n");
    } else {
        printf("EASY\n");
    }
    
    return 0;
}
