#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string remix;
    cin >> remix;

    int len = remix.length();
    int i = 0;
    bool first_word = true;

    while (i < len) {
        // Check if current position starts with "WUB"
        if (i + 2 < len && remix[i] == 'W' && remix[i+1] == 'U' && remix[i+2] == 'B') {
            i += 3;  // Skip "WUB"
        } else {
            // Found start of a word
            if (!first_word) {
                cout << ' ';
            }

            // Print characters until next "WUB" or end of string
            while (i < len &&
                   !(i + 2 < len && remix[i] == 'W' && remix[i+1] == 'U' && remix[i+2] == 'B')) {
                cout << remix[i];
                ++i;
            }

            first_word = false;
        }
    }

    cout << '\n';
    return 0;
}

