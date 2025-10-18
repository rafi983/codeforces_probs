#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int na, ma;
    scanf("%d %d", &na, &ma);
    
    char table1[MAX_SIZE][MAX_SIZE + 1];
    for (int i = 0; i < na; i++) {
        scanf("%s", table1[i]);
    }
    
    int nb, mb;
    scanf("%d %d", &nb, &mb);
    
    char table2[MAX_SIZE][MAX_SIZE + 1];
    for (int i = 0; i < nb; i++) {
        scanf("%s", table2[i]);
    }
    
    int max_overlap = -1;
    int best_x = 0, best_y = 0;
    

    for (int x = 1 - na; x <= nb - 1; x++) {
        for (int y = 1 - ma; y <= mb - 1; y++) {
            int overlap = 0;
            
            for (int i = 1; i <= na; i++) {
                for (int j = 1; j <= ma; j++) {
                    int i2 = i + x;
                    int j2 = j + y;
                    
                    if (i2 >= 1 && i2 <= nb && j2 >= 1 && j2 <= mb) {
                        if (table1[i-1][j-1] == '1' && table2[i2-1][j2-1] == '1') {
                            overlap++;
                        }
                    }
                }
            }
            
            if (overlap > max_overlap) {
                max_overlap = overlap;
                best_x = x;
                best_y = y;
            }
        }
    }
    
    printf("%d %d\n", best_x, best_y);
    
    return 0;
}
