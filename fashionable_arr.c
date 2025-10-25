#include <stdio.h>
#include <stdlib.h>

int solve_test_case() {
    int n;
    scanf("%d", &n);
    
    int arr[50];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (n == 1) {
        return 0;
    }
    
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    if ((min + max) % 2 == 0) {
        return 0;
    }
    
    int min_operations = n; // Worst case: remove all elements except one
    
    for (int i = 0; i < n; i++) {
        int potential_min = arr[i];
        
        for (int j = 0; j < n; j++) {
            int potential_max = arr[j];
            
            if ((potential_min + potential_max) % 2 != 0 || potential_min > potential_max) {
                continue;
            }
            
            int operations = 0;
            for (int k = 0; k < n; k++) {
                // Remove if element is smaller than new min or larger than new max
                if (arr[k] < potential_min || arr[k] > potential_max) {
                    operations++;
                }
            }
            
            if (operations < min_operations) {
                min_operations = operations;
            }
        }
    }
    
    return min_operations;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int result = solve_test_case();
        printf("%d\n", result);
    }
    
    return 0;
}
