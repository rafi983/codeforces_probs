#include <stdio.h>
#include <string.h>

// Function to get number of faces for a polyhedron
int get_faces(char *polyhedron) {
    if (strcmp(polyhedron, "Tetrahedron") == 0) return 4;
    if (strcmp(polyhedron, "Cube") == 0) return 6;
    if (strcmp(polyhedron, "Octahedron") == 0) return 8;
    if (strcmp(polyhedron, "Dodecahedron") == 0) return 12;
    if (strcmp(polyhedron, "Icosahedron") == 0) return 20;
    return 0;  // Should never happen given input constraints
}

int main() {
    int n;
    scanf("%d", &n);
    
    int total_faces = 0;
    char polyhedron[13];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", polyhedron);
        total_faces += get_faces(polyhedron);
    }
    
    printf("%d\n", total_faces);
    return 0;
}
