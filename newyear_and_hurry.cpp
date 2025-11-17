#include <iostream>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    int remaining = 240 - k;
    if (remaining <= 0) {
        cout << "0" << endl;
        return 0;
    }

    int solved = 0;
    for (int i = 1; i <= n; i++) {
        int time_needed = 5 * i;
        if (remaining - time_needed >= 0) {
            remaining -= time_needed;
            solved++;
        } else {
            break;
        }
    }

    cout << solved << endl;
    return 0;
}

