#include <iostream>
using namespace std;

int main() {
    long long k, n, w;
    cin >> k >> n >> w;

    long long total_cost = k * w * (w + 1) / 2; // arithmetic series sum
    long long borrow = total_cost - n;
    if (borrow < 0) {
        borrow = 0;
    }
    cout << borrow << endl;
    return 0;
}

