#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;

    if (c == 'z') {
        cout << "a" << endl;
    } else if (c >= 'a' && c < 'z') {
        cout << (char)(c + 1) << endl;
    } else {
        cout << "Invalid input" << endl;
    }

    return 0;
}

