#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (y >= x + 1) {
            cout << 2 << endl;
        } else if (x >= y + 2 && y >= 2) {
            cout << 3 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}

