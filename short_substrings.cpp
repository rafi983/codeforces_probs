#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        char b[101];
        cin >> b;

        int len = strlen(b);

        cout << b[0];
        for (int i = 1; i < len; i += 2) {
            cout << b[i];
        }
        cout << endl;
    }

    return 0;
}

