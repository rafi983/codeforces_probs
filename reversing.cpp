#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    unsigned int a[1005];
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = n - 1; i >= 0; --i) {
        cout << a[i];
        if (i) cout << " ";
    }
    cout << endl;

    return 0;
}

