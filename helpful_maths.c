#include <stdio.h>
#include <string.h>

int main(void) {
    char s[105];
    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 0;
    }

    int count[4] = {0};
    int len = (int)strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] >= '1' && s[i] <= '3') {
            ++count[s[i] - '0'];
        }
    }

    int first = 1;
    for (int digit = 1; digit <= 3; ++digit) {
        for (int j = 0; j < count[digit]; ++j) {
            if (!first) {
                printf("+");
            }
            printf("%d", digit);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
