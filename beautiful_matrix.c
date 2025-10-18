#include <stdio.h>
#include <stdlib.h>  // for abs()

int main() {
    int matrix[5][5];
    int row_1, col_1;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1) {
                row_1 = i;
                col_1 = j;
            }
        }
    }
    
    
    printf("%d\n", abs(row_1 - 2) + abs(col_1 - 2));
    
    return 0;
}
