#include <stdio.h>
#include <string.h>

int main(void) {
    char s[105];
    char t[105];

    if (fgets(s, sizeof(s), stdin) == NULL || fgets(t, sizeof(t), stdin) == NULL) {
        return 0;
    }

    int len_s = (int)strlen(s);
    int len_t = (int)strlen(t);

    if (s[len_s - 1] == '\n') {
        s[len_s - 1] = '\0';
        --len_s;
    }
    if (t[len_t - 1] == '\n') {
        t[len_t - 1] = '\0';
        --len_t;
    }

    if (len_s != len_t) {
        printf("NO\n");
        return 0;
    }

    int match = 1;
    for (int i = 0; i < len_s; ++i) {
        if (s[i] != t[len_s - 1 - i]) {
            match = 0;
            break;
        }
    }

    if (match) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
