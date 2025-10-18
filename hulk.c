#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            printf("I hate");
        } else {
            printf("I love");
        }
        
        if (i < n) {
            printf(" that ");
        }
    }
    printf(" it\n");

    return 0;
}
