#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string guest, host, pile;
    cin >> guest >> host >> pile;

    vector<int> letters(26, 0);

    for (char c : guest) {
        letters[c - 'A']++;
    }
    for (char c : host) {
        letters[c - 'A']++;
    }

    for (char c : pile) {
        letters[c - 'A']--;
    }

    for (int count : letters) {
        if (count != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}

