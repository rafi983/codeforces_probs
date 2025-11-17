#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            cout << "I hate";
        } else {
            cout << "I love";
        }

        if (i < n) {
            cout << " that ";
        }
    }
    cout << " it" << endl;

    return 0;
}

