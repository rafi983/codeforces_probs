#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string expression;
        cin >> expression;

        int a = expression[0] - '0';
        int b = expression[2] - '0';

        cout << a + b << '\n';
    }

    return 0;
}

