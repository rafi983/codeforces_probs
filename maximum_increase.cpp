#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long prev = 0, cur = 0;
    int best = 0, len = 0;

    for (int i = 0; i < n; ++i) {
        cin >> cur;
        if (i == 0 || cur <= prev) {
            len = 1;
        } else {
            ++len;
        }
        if (len > best) best = len;
        prev = cur;
    }

    cout << best << endl;
    return 0;
}

