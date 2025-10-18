#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int mishka_wins = 0;
    int chris_wins = 0;

    for (int i = 0; i < n; ++i) {
        int mi, ci;
        if (scanf("%d %d", &mi, &ci) != 2) {
            return 0;
        }

        if (mi > ci) {
            ++mishka_wins;
        } else if (ci > mi) {
            ++chris_wins;
        }
    }

    if (mishka_wins > chris_wins) {
        printf("Mishka\n");
    } else if (chris_wins > mishka_wins) {
        printf("Chris\n");
    } else {
        printf("Friendship is magic!^^\n");
    }

    return 0;
}
