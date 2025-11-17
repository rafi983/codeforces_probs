#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int len = s.length();
    bool change_case = false;

    if (len == 0) {
        // Empty string, do nothing
    } else if (len == 1) {
        // Single letter, always flip case
        change_case = true;
    } else {
        // Check if all characters from the second one are uppercase
        bool rest_are_upper = true;
        for (int i = 1; i < len; ++i) {
            if (islower(s[i])) {
                rest_are_upper = false;
                break;
            }
        }
        // If they are, the rule applies
        if (rest_are_upper) {
            change_case = true;
        }
    }

    if (change_case) {
        for (char& c : s) {
            if (islower(c)) {
                c = toupper(c);
            } else {
                c = tolower(c);
            }
        }
    }

    cout << s << '\n';

    return 0;
}

