#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10000000
#define ALPHABET_SIZE 26

int main(void) {
    char buffer[1024];
    int frequency[ALPHABET_SIZE] = {0};
    int c;
    
    while ((c = getchar()) != EOF && c != '\n') {
        if (c >= 'a' && c <= 'z') {
            frequency[c - 'a']++;
        }
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > 0) {
            printf("%c : %d\n", 'a' + i, frequency[i]);
        }
    }
    
    return 0;
}
