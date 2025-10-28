#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char expression[10];
        scanf("%s", expression);

        int a = expression[0] - '0';
        int b = expression[2] - '0';

        printf("%d\n", a + b);
    }

    return 0;
}

