#include <stdio.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int minimum = min(a, min(b, c));
        int maximum = max(a, max(b, c));
        int medium = a + b + c - minimum - maximum;

        printf("%d\n", medium);
    }

    return 0;
}

