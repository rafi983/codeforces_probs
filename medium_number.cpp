#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int minimum = min(a, min(b, c));
        int maximum = max(a, max(b, c));
        int medium = a + b + c - minimum - maximum;

        cout << medium << endl;
    }

    return 0;
}

