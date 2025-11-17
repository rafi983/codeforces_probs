#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string x;
        cin >> x;

        int digit = x[0] - '0';
        int length = x.length();

        int total = 0;

        total += (digit - 1) * 10;

        total += (length * (length + 1)) / 2;

        cout << total << '\n';
    }

    return 0;
}

