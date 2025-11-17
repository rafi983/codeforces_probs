#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 1;

    int len = s.length();

    bool is_palindrome = true;
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    cout << (is_palindrome ? "YES" : "NO") << endl;
    return 0;
}

