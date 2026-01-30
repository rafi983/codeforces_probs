#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> round_numbers;
    int power = 1;

    while (n > 0) {
        int digit = n % 10;
        if (digit > 0) {
            round_numbers.push_back(digit * power);
        }
        n /= 10;
        power *= 10;
    }

    cout << round_numbers.size() << endl;
    for (size_t i = 0; i < round_numbers.size(); ++i) {
        cout << round_numbers[i] << (i == round_numbers.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
