#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int first_digit = N / 10;   // Tens place
    int second_digit = N % 10;  // Units place

    bool is_lucky = false;

    if (second_digit != 0 && first_digit % second_digit == 0) {
        is_lucky = true;
    }

    if (first_digit != 0 && second_digit % first_digit == 0) {
        is_lucky = true;
    }

    if (is_lucky) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

