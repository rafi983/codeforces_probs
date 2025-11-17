#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<unsigned int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = n - 1;
    bool ok = true;

    while (l < r) {
        if (a[l] != a[r]) {
            ok = false;
            break;
        }
        ++l;
        --r;
    }

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}

