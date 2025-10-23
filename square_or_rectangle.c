#include <stdio.h>

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 1;
    
    while (t--) {
        int w, h;
        if (scanf("%d %d", &w, &h) != 2) return 1;
        puts(w == h ? "Square" : "Rectangle");
    }
    
    return 0;
}
