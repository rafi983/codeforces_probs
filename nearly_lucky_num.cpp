#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;

    int count = 0;
    for (char c : n) {
        if (c == '4' || c == '7') {
            count++;
        }
    }

    if (count == 0) {
        cout << "NO" << endl;
        return 0;
    }

    string count_str = to_string(count);

    bool is_lucky = true;
    for (char c : count_str) {
        if (c != '4' && c != '7') {
            is_lucky = false;
            break;
        }
    }

    if (is_lucky) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

