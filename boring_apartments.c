#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char x[5];
        scanf("%s", x);

        int digit = x[0] - '0';
        int length = strlen(x);

        int total = 0;

        total += (digit - 1) * 10;

        total += (length * (length + 1)) / 2;

        printf("%d\n", total);
    }

    return 0;
}

