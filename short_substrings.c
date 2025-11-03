#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char b[101];
        scanf("%s", b);

        int len = strlen(b);

        printf("%c", b[0]);
        for (int i = 1; i < len; i += 2) {
            printf("%c", b[i]);
        }
        printf("\n");
    }

    return 0;
}

