#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int anton_wins = 0, danik_wins = 0;

    for (char c : s) {
        if (c == 'A') {
            anton_wins++;
        } else if (c == 'D') {
            danik_wins++;
        }
    }

    if (anton_wins > danik_wins) {
        cout << "Anton\n";
    } else if (danik_wins > anton_wins) {
        cout << "Danik\n";
    } else {
        cout << "Friendship\n";
    }

    return 0;
}

