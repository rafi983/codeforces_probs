#include <stdio.h>
#include <string.h>

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    
    char s[51];
    scanf("%s", s);
    
    // Simulate t seconds
    for (int time = 0; time < t; time++) {
        // For each second, check positions from left to right
        for (int i = 0; i < n - 1; i++) {
            // If boy is at position i and girl at position i+1, swap them
            if (s[i] == 'B' && s[i + 1] == 'G') {
                char temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                i++; // Skip next position since we just swapped
            }
        }
    }
    
    printf("%s\n", s);
    
    return 0;
}
