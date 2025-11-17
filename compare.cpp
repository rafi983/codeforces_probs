#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    if (str1 <= str2) {
        cout << str1 << '\n';
    } else {
        cout << str2 << '\n';
    }

    return 0;
}

