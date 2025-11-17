#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    int mishka_wins = 0;
    int chris_wins = 0;

    for (int i = 0; i < n; ++i) {
        int mi, ci;
        if (!(cin >> mi >> ci)) {
            return 0;
        }

        if (mi > ci) {
            ++mishka_wins;
        } else if (ci > mi) {
            ++chris_wins;
        }
    }

    if (mishka_wins > chris_wins) {
        cout << "Mishka" << endl;
    } else if (chris_wins > mishka_wins) {
        cout << "Chris" << endl;
    } else {
        cout << "Friendship is magic!^^" << endl;
    }

    return 0;
}

