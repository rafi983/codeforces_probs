#include <iostream>
using namespace std;

int main() {
    int n = 0;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    int givers[100] = {0};
    for (int receiver = 1; receiver <= n; ++receiver) {
        int giver = 0;
        if (!(cin >> giver)) {
            giver = 0;
        }
        if (giver >= 1 && giver <= n) {
            givers[giver - 1] = receiver;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << " ";
        }
        cout << givers[i];
    }
    cout << endl;
    return 0;
}

