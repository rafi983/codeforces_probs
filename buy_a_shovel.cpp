#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, r;
    cin >> k >> r;

    int count = 1;
    while (true) {
        long long total_cost = static_cast<long long>(count) * k;
        if (total_cost % 10 == 0 || total_cost % 10 == r) {
            cout << count << '\n';
            break;
        }
        ++count;
    }

    return 0;
}

