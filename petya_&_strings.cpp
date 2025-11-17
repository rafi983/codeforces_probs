#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int len = s1.length();
    int result = 0;

    for (int i = 0; i < len; i++) {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);

        if (c1 < c2) {
            result = -1;
            break;
        } else if (c1 > c2) {
            result = 1;
            break;
        }
    }

    cout << result << endl;

    return 0;
}

