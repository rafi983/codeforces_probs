#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to get number of faces for a polyhedron
int getFaces(const string& polyhedron) {
    static const unordered_map<string, int> faces = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };

    auto it = faces.find(polyhedron);
    return (it != faces.end()) ? it->second : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total_faces = 0;

    for (int i = 0; i < n; ++i) {
        string polyhedron;
        cin >> polyhedron;
        total_faces += getFaces(polyhedron);
    }

    cout << total_faces << '\n';

    return 0;
}

