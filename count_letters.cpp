#include <iostream>
#include <vector>
using namespace std;

constexpr int ALPHABET_SIZE = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> frequency(ALPHABET_SIZE, 0);
    char c;

    while (cin.get(c) && c != '\n') {
        if (c >= 'a' && c <= 'z') {
            frequency[c - 'a']++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (frequency[i] > 0) {
            cout << static_cast<char>('a' + i) << " : " << frequency[i] << '\n';
        }
    }

    return 0;
}

