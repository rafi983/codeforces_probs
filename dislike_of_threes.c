#include <stdio.h>

int liked_numbers[1001];

void precompute() {
    int count = 1;
    int num = 1;
    while (count <= 1000) {
        if (num % 3 != 0 && num % 10 != 3) {
            liked_numbers[count] = num;
            count++;
        }
        num++;
    }
}

void solve() {
    int k;
    scanf("%d", &k);
    printf("%d\n", liked_numbers[k]);
}

int main() {
    precompute();
    
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    
    return 0;
}
