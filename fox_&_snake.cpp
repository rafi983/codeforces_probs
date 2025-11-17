#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int row = 1; row <= n; ++row) {
        if (row % 2 == 1) {
            // Odd rows: all '#'
            for (int col = 0; col < m; ++col) {
                cout << '#';
            }
        } else {
            // Even rows: '#' on alternating sides
            bool place_right = ((row / 2) % 2 == 1);
            for (int col = 0; col < m; ++col) {
                if ((place_right && col == m - 1) || (!place_right && col == 0)) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            }
        }
        cout << '\n';
    }

    return 0;
}

