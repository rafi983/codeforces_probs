#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int current_passengers = 0;
    int max_capacity = 0;
    
    for (int i = 0; i < n; i++) {
        int exit, enter;
        scanf("%d %d", &exit, &enter);
        
        // Passengers exit first
        current_passengers -= exit;
        
        // Then passengers enter
        current_passengers += enter;
        
        // Update the maximum capacity needed
        if (current_passengers > max_capacity) {
            max_capacity = current_passengers;
        }
    }
    
    printf("%d\n", max_capacity);
    
    return 0;
}
