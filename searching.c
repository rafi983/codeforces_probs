#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int A[100005];
    

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    int X;
    scanf("%d", &X);
    
    int position = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            position = i;
            break;
        }
    }
    
    printf("%d\n", position);
    
    return 0;
}
