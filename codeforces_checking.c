#include <stdio.h>
#include <string.h>

void solve() {
    char c;
    scanf(" %c", &c);
    char *s = "codeforces";
    if (strchr(s, c)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
