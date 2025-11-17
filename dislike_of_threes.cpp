#include <iostream>
#include <vector>
using namespace std;

vector<int> liked_numbers(1001);

void precompute() {
    int count = 1;
    int num = 1;
    while (count <= 1000) {
        if (num % 3 != 0 && num % 10 != 3) {
            liked_numbers[count] = num;
            ++count;
        }
        ++num;
    }
}

void solve() {
    int k;
    cin >> k;
    cout << liked_numbers[k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

