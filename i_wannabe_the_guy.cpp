#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> levels(n + 1, false); // Levels are 1 to n
    int p, level_index;

    // Read Little X's levels
    cin >> p;
    for (int i = 0; i < p; i++) {
        cin >> level_index;
        levels[level_index] = true;
    }

    // Read Little Y's levels
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> level_index;
        levels[level_index] = true;
    }

    // Check if all levels are covered
    bool all_levels_passed = true;
    for (int i = 1; i <= n; i++) {
        if (!levels[i]) {
            all_levels_passed = false;
            break;
        }
    }

    if (all_levels_passed) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}

