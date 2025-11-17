#include <iostream>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) {
        return 0;
    }

    const long long limit = 1000000000000LL;

    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        if (y == 1) {
            cout << "-1" << endl;
            continue;
        }

        long long pos = k;
        bool overflow = false;

        for (long long i = 0; i < x && pos <= limit; i++) {
            long long add = (pos - 1) / (y - 1);
            if (pos > limit - add) {
                overflow = true;
                break;
            }
            pos += add;
        }

        if (overflow || pos > limit) {
            cout << "-1" << endl;
        } else {
            cout << pos << endl;
        }
    }

    return 0;
}

