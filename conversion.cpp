#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    for (char c : s) {
        if (c == ',') {
            cout << ' ';
        } else if (isupper(c)) {
            cout << static_cast<char>(tolower(c));
        } else if (islower(c)) {
            cout << static_cast<char>(toupper(c));
        } else {
            cout << c;
        }
    }
    cout << '\n';

    return 0;
}

