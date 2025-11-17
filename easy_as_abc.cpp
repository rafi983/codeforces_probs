#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int GRID_SIZE = 3;

vector<int> dr = {0, -1, -1, -1, 0, 1, 1, 1};
vector<int> dc = {1, 1, 0, -1, -1, -1, 0, 1};

bool isValid(int r, int c) {
    return r >= 0 && r < GRID_SIZE && c >= 0 && c < GRID_SIZE;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> grid(GRID_SIZE);

    // Read the 3x3 grid
    for (int i = 0; i < GRID_SIZE; ++i) {
        cin >> grid[i];
    }

    string best = "ZZZ"; // Initialize to max possible

    // Try all possible starting positions
    for (int r1 = 0; r1 < GRID_SIZE; ++r1) {
        for (int c1 = 0; c1 < GRID_SIZE; ++c1) {
            // Try all 8 directions for second cell
            for (int d1 = 0; d1 < 8; ++d1) {
                int r2 = r1 + dr[d1];
                int c2 = c1 + dc[d1];
                if (!isValid(r2, c2)) continue;

                // Try all 8 directions for third cell from second cell
                for (int d2 = 0; d2 < 8; ++d2) {
                    int r3 = r2 + dr[d2];
                    int c3 = c2 + dc[d2];
                    if (!isValid(r3, c3)) continue;

                    // Check that all three cells are different
                    if ((r1 == r2 && c1 == c2) ||
                        (r2 == r3 && c2 == c3) ||
                        (r1 == r3 && c1 == c3)) continue;

                    // Form the word
                    string word;
                    word += grid[r1][c1];
                    word += grid[r2][c2];
                    word += grid[r3][c3];

                    // Check if it's better (lexicographically smaller)
                    if (word < best) {
                        best = word;
                    }
                }
            }
        }
    }

    cout << best << '\n';

    return 0;
}

