#include <iostream>
#include <string>
using namespace std;

int main() {
    string program;
    if (!getline(cin, program)) {
        return 0;
    }

    for (char c : program) {
        if (c == 'H' || c == 'Q' || c == '9') {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}

