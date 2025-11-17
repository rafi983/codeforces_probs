#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bool is_colored = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char pixel;
            cin >> pixel;
            if (pixel == 'C' || pixel == 'M' || pixel == 'Y') {
                is_colored = true;
            }
        }
    }

    if (is_colored) {
        cout << "#Color\n";
    } else {
        cout << "#Black&White\n";
    }

    return 0;
}

