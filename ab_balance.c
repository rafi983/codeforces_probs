#include <stdio.h>
#include <string.h>

int countAB(char *s) {
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == 'a' && s[i+1] == 'b') {
            count++;
        }
    }
    return count;
}

int countBA(char *s) {
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == 'b' && s[i+1] == 'a') {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[101];
        scanf("%s", s);

        int ab = countAB(s);
        int ba = countBA(s);

        if (ab == ba) {
            printf("%s\n", s);
            continue;
        }

        char original_first = s[0];
        s[0] = (s[0] == 'a') ? 'b' : 'a';
        if (countAB(s) == countBA(s)) {
            printf("%s\n", s);
            s[0] = original_first;
            continue;
        }
        s[0] = original_first;

        int len = strlen(s);
        char original_last = s[len-1];
        s[len-1] = (s[len-1] == 'a') ? 'b' : 'a';
        if (countAB(s) == countBA(s)) {
            printf("%s\n", s);
            s[len-1] = original_last;
            continue;
        }
        s[len-1] = original_last;

        printf("%s\n", s);
    }

    return 0;
}

