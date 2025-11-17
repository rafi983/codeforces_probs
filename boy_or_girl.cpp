#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string username;
    cin >> username;

    vector<bool> char_present(26, false);

    for (char c : username) {
        char_present[c - 'a'] = true;
    }

    int distinct_count = 0;
    for (bool present : char_present) {
        if (present) {
            ++distinct_count;
        }
    }

    if (distinct_count % 2 == 1) {
        cout << "IGNORE HIM!\n";
    } else {
        cout << "CHAT WITH HER!\n";
    }

    return 0;
}

