#include <iostream>
#include <vector>
using namespace std;

bool hasDistinctDigits(int year) {
    vector<int> digits(10, 0);

    while (year > 0) {
        int digit = year % 10;
        if (digits[digit] > 0) {
            return false;
        }
        digits[digit] = 1;
        year /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int y;
    cin >> y;

    ++y;
    while (!hasDistinctDigits(y)) {
        ++y;
    }

    cout << y << '\n';

    return 0;
}

