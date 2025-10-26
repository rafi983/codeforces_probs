#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int d[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        total += d[i];
    }

    int s, t;
    scanf("%d %d", &s, &t);

    if (s == t) {
        printf("0\n");
        return 0;
    }

    if (s > t) {
        int temp = s;
        s = t;
        t = temp;
    }

    int dist_clockwise = 0;
    for (int i = s - 1; i < t - 1; i++) {
        dist_clockwise += d[i];
    }

    int dist_counterclockwise = total - dist_clockwise;

    if (dist_clockwise < dist_counterclockwise) {
        printf("%d\n", dist_clockwise);
    } else {
        printf("%d\n", dist_counterclockwise);
    }

    return 0;
}
