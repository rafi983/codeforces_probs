#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    if (n < 26) {
        printf("NO\n");
        return 0;
    }

    int alphabet[26] = {0};
    for (int i = 0; i < n; i++) {
        alphabet[tolower(s[i]) - 'a'] = 1;
    }

    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += alphabet[i];
    }

    if (sum == 26) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
