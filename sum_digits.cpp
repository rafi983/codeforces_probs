#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    char digit;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> digit;
        if (digit >= '0' && digit <= '9') {
            sum += (digit - '0');  // Convert ASCII digit to integer value
        }
    }

    cout << sum << endl;

    return 0;
}

