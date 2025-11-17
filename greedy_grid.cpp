#include <iostream>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n > 1 && m > 1 && (n != 2 || m != 2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

