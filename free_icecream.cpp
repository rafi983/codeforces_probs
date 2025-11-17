#include <iostream>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    long long packs = x;
    int distressed = 0;

    for (int i = 0; i < n; i++) {
        char sign;
        long long d;

        cin >> sign >> d;

        if (sign == '+') {
            packs += d;
        } else {
            if (packs >= d) {
                packs -= d;
            } else {
                distressed++;
            }
        }
    }

    cout << packs << " " << distressed << endl;
    return 0;
}

