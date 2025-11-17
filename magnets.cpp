#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    int groups = 1;
    string prev_magnet;
    string current_magnet;

    cin >> prev_magnet;

    for (int i = 1; i < n; i++) {
        cin >> current_magnet;

        if (prev_magnet[1] == current_magnet[0]) {
            groups++;
        }
        prev_magnet = current_magnet;
    }

    cout << groups << endl;

    return 0;
}

