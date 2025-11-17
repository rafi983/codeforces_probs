#include <iostream>
using namespace std;

bool isComposite(int n) {
    if (n <= 3) return false;
    if (n % 2 == 0) return true;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        if (isComposite(n / 2)) {
            cout << n / 2 << ' ' << n / 2 << '\n';
        } else {
            cout << n - 8 << ' ' << 8 << '\n';
        }
    } else {
        cout << n - 9 << ' ' << 9 << '\n';
    }

    return 0;
}

