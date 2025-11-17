#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) {
        return 0;
    }

    int count[4] = {0};

    for (char c : s) {
        if (c >= '1' && c <= '3') {
            count[c - '0']++;
        }
    }

    bool first = true;
    for (int digit = 1; digit <= 3; digit++) {
        for (int j = 0; j < count[digit]; j++) {
            if (!first) {
                cout << "+";
            }
            cout << digit;
            first = false;
        }
    }
    cout << endl;

    return 0;
}

