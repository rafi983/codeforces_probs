#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n < 26) {
        cout << "NO" << endl;
        return 0;
    }

    bool alphabet[26] = {false};
    for (int i = 0; i < n; i++) {
        alphabet[tolower(s[i]) - 'a'] = true;
    }

    int sum = 0;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i]) sum++;
    }

    if (sum == 26) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

