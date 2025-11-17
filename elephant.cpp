#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int steps = (x + 4) / 5;  // Ceiling division: (x + 5 - 1) / 5

    cout << steps << '\n';

    return 0;
}

