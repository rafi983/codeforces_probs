#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 1) {
            cout << "-1" << endl;
        } else {
            cout << "0 0 " << n / 2 << endl;
        }
    }

    return 0;
}

