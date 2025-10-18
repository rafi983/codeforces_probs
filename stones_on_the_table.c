#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    char s[55];
    if (scanf("%s", s) != 1) {
        return 0;
    }
    int removals = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            removals++;
        }
    }
    printf("%d\n", removals);
    return 0;
}
