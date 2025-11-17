#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        sum += num;
    }

    if (sum < 0) {
        sum = -sum;
    }

    cout << sum << endl;

    return 0;
}

