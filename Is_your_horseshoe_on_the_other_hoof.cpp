#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long s[4];
    int duplicates = 0;

    // Read the four horseshoe colors
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }

    // Sort the array to bring identical colors together
    sort(s, s + 4);

    // Count the number of duplicate colors
    for (int i = 0; i < 3; i++) {
        if (s[i] == s[i + 1]) {
            duplicates++;
        }
    }

    // The number of horseshoes to buy is the number of duplicates
    cout << duplicates << endl;

    return 0;
}

