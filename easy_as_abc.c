#include <stdio.h>
#include <string.h>

char grid[3][4]; // 3x3 grid + null terminators
char best[4] = "ZZZ"; // Initialize to max possible

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

int is_valid(int r, int c) {
    return r >= 0 && r < 3 && c >= 0 && c < 3;
}

void update_best(char *word) {
    if (strcmp(word, best) < 0) {
        strcpy(best, word);
    }
}

int main(void) {
    // Read the 3x3 grid
    for (int i = 0; i < 3; i++) {
        if (scanf("%s", grid[i]) != 1) return 1;
    }
    
    // Try all possible starting positions
    for (int r1 = 0; r1 < 3; r1++) {
        for (int c1 = 0; c1 < 3; c1++) {
            // Try all 8 directions for second cell
            for (int d1 = 0; d1 < 8; d1++) {
                int r2 = r1 + dr[d1];
                int c2 = c1 + dc[d1];
                if (!is_valid(r2, c2)) continue;
                
                // Try all 8 directions for third cell from second cell
                for (int d2 = 0; d2 < 8; d2++) {
                    int r3 = r2 + dr[d2];
                    int c3 = c2 + dc[d2];
                    if (!is_valid(r3, c3)) continue;
                    
                    // Check that all three cells are different
                    if ((r1 == r2 && c1 == c2) || 
                        (r2 == r3 && c2 == c3) || 
                        (r1 == r3 && c1 == c3)) continue;
                    
                    // Form the word and check if it's better
                    char word[4];
                    word[0] = grid[r1][c1];
                    word[1] = grid[r2][c2];
                    word[2] = grid[r3][c3];
                    word[3] = '\0';
                    
                    update_best(word);
                }
            }
        }
    }
    
    printf("%s\n", best);
    return 0;
}
