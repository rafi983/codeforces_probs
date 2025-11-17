#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long m;
        cin >> m;

        long long power = 1;
        long long temp = m;

        while (temp >= 10) {
            temp /= 10;
            power *= 10;
        }

        cout << m - power << endl;
    }

    return 0;
}

