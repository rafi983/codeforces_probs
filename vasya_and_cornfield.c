#include <stdio.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        
        if (x + y >= d && x - y <= d && x + y <= 2*n - d && y - x <= d) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
