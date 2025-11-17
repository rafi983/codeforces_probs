#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> matrix(5, vector<int>(5));
    int row_1, col_1;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                row_1 = i;
                col_1 = j;
            }
        }
    }

    cout << abs(row_1 - 2) + abs(col_1 - 2) << '\n';

    return 0;
}

