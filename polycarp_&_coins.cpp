#include <iostream>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long n;
        cin >> n;

        long long a = n / 3;
        long long r = n % 3;
        long long c1 = a, c2 = a;

        if (r == 1) c1++;
        else if (r == 2) c2++;

        cout << c1 << " " << c2 << endl;
    }

    return 0;
}

