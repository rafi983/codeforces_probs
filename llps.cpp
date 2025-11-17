#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;

    char mx = 'a';
    for (char c : s) {
        if (c > mx) mx = c;
    }

    for (char c : s) {
        if (c == mx) cout << mx;
    }
    cout << endl;

    return 0;
}

